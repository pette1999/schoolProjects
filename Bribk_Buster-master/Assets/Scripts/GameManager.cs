using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public int lives = 3;
    public int bricks = 0;
    public int score = 0;
    public float resetDelay = 1f;
    public GameObject paddle;
    public LevelManager lm;
    public GameObject deathParticles;
    private GameObject clonePaddle;
    public Text livesText;
    public Text scoreText;
    public Text gameOverTxt;

    /*
     * Awake()
     *      make sure our game is ready for play prior to the player being able to modify any of the variables or trigger any functions.   
     */
    void Awake()
    {
        Setup();
    }

    /*
     * Setup()
     *      Find all the GameObjects in our scene with the tag “bricks” and add them to an array.
     *      Update the text component.
     *      Reset the brick variable to 0 before it is set. This is just to avoid any bugs later on by setting it to 0 before they are counted.
     */
    void Setup()
    {
        SetupPaddle();
        livesText.text = "Balls Remaining : " + lives;
        scoreText.text = "Score : " + score;
        lm.LoadNextLevel();
        bricks = 0;
        bricks = GameObject.FindGameObjectsWithTag("Brick").Length;
    }

    /*
     * LoseLife()
     *      life - 1
     *      Destroy the old paddle prior to instantiating a new one. Remember, since we made our ball a child to our paddle we get a new ball when we instantiate a new paddle.
     *      If we have more than -1 lives, we will invoke the “SetupPaddle” function to spawn a new paddle. The reason we use -1 is so our player can still play when they have “0” lives remaining. 
     *      Instantiate a particle effect where our player’s paddle is when the ball collides with the “DestroyBallZone”.
     *      Display lives.   
     */
    public void LoseLife()
    {
        lives--;
        livesText.text = "Balls Remaining : " + lives;
        Destroy(clonePaddle);
        Instantiate(deathParticles, clonePaddle.transform.position, Quaternion.identity);
        if (lives > -1)
        {
            Invoke("SetupPaddle", resetDelay);
        }

        CheckGameOver();
    }

    /*
     * SetupPaddle()
     *      Instantiate a clone paddle and assign it to a private variable. We use a private variable to make sure it is not accessible by other scripts.   
     */
    void SetupPaddle()
    {
        clonePaddle = Instantiate(paddle, paddle.transform.position, paddle.transform.rotation) as
        GameObject;
    }

    /*
     * DestroyBrick()
     *      Add +1 to the player’s score when a brick is destroied. 
     *      Add score to display when a brick is destroied.
     *      Check Gameover or not. 
     */
    public void DestroyBrick()
    {
        bricks--;
        score++;
        scoreText.text = "Score : " + score;
        CheckGameOver();
    }

    /*
     * CheckGameOver()
     *      To check and see if our player has lost we want to see if they have any lives remaining.
     *      When they are at “0” lives, are technically using their last life, we check to see if lives is less than 0. If so, they have lost. 
     *      Turn on the “gameOverTxt” GameObject before we can access its components and update them.
     *      Set our text to a specific string.  
     *      With Time.timeScale we are slowing down the speed at which time passes in-game. We slow it down in the CheckGameOver(), then return it to normal speed in the LevelComplete() and Reset() functions.
     *      Invoke loads a function after a short delay.
     *      lm.LoadNextLevel() is us calling our LoadNextLevel() function that is in our LevelManager script.
     *      SceneManager.LoadScene(“BrickGame”) will reload a scene from a string. Make sure whatever your scene is called is what you have between the quotes, otherwise this will not work.   
     */
    void CheckGameOver()
    {
        if (bricks < 1)
        {
            //Debug.Log("Player wins!");
            gameOverTxt.gameObject.SetActive(true);
            gameOverTxt.text = "Great job!";
            Time.timeScale = .25f;
            Destroy(GameObject.FindGameObjectWithTag("Ball"));
            Invoke("LevelComplete", resetDelay);
        }
        if (lives < 0)
        {
            //Debug.Log("Player lost.");
            gameOverTxt.gameObject.SetActive(true);
            gameOverTxt.text = "Try Again";
            livesText.text = "GAME OVER";
            Time.timeScale = .25f;
            Invoke("Reset", resetDelay);
        }
    }

    void LevelComplete()
    {
        gameOverTxt.gameObject.SetActive(false);
        Time.timeScale = 1f;
        Destroy(clonePaddle);
        Setup();
    }

    void Reset()
    {
        Time.timeScale = 1f;
        SceneManager.LoadScene("Game");
    }

    void MultiplierDeactivate()
    {
        scoreText.fontStyle = FontStyle.Normal;
        scoreText.fontSize = 20;
        scoreText.color = Color.white;
    }

    /*
     * MultiplierActivate(float multiplierDuration)
     *      Parameter float multiplierDuration: float type
     *      Activate the Multiplier and set the duration before it expires.
     *      Invokes the function in quotes with a delay. In this case, MultiplierDeactivate();
     *      Use this to reset all the changes to the GameObjects and their components.   
     *      We are updating various text components: The Score text’s font style to bold, the font size to 26, and the color to green.
     *      We are resetting various text component values to what they were prior to the changes in MultiplierActiivate().
     */
    public void MultiplierActivate(float multiplierDuration)
    {
        score++;
        scoreText.fontStyle = FontStyle.Bold;
        scoreText.fontSize = 26;
        scoreText.color = Color.green;
        Invoke("MultiplierDeactivate", multiplierDuration);
    }

    /*
     * OnApplicationQuit()
     *      Quit the application.   
     */
    public void OnApplicationQuit()
    {
        #if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
        #else
            Application.Quit();
        #endif
    }
}
