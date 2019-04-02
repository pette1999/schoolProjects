using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PaddleBoost : MonoBehaviour
{
    bool boost = false;//Setting a bool we can set to true while the boost is active.
    public float paddleBoost = 1f;//Setting the force which will be applied to the ball on collision.
    private Renderer rend;//set a private variable to be used when updating the color of the paddle.
    public GameObject boostNotification;//the prefab we will instantiate that floats up and displays our bonus text.
    private GameManager gm;//private reference to the GameManager script.
    public float multiplierDuration = 5f;//The duration of how long the multiplier will last.

    /*
     * Start()
     *      Start is called before the first frame update
     *      rend = GetComponent<Renderer> (); -> Get the renderer of this GameObject and set it as “rend”.
     *      rend.material.color = Color.cyan; -> Set the material color to be cyan.
     *      gm = GameObject.Find ("GameManager").GetComponent<GameManager>(); -> Find and assign the GameManager script to this variable.   
     */
    void Start()
    {
        rend = GetComponent<Renderer>();
        rend.material.color = Color.yellow;
        gm = GameObject.Find("GameManager").GetComponent<GameManager>();
    }

    /*
     * OnCollisionEnter(Collision col)
     *      if (col.gameObject.tag == "Ball") -> Checks to see if the collision object tag was “Ball”.
     *      col.gameObject.GetComponent<Rigidbody>().AddForce(new Vector3(paddleBoost, paddleBoost, 0)); -> Add’s force to the ball’s velocity on the X and Y transforms.
     *      Instantiate (boostNotification, this.gameObject.transform.position, Quaternion.identity); -> Instantiate the “BoostNotification” GameObject at the paddle’s transform.position. This allows the text to appear right above the paddle when the function is triggered.
     *      gm.MultiplierActivate(multiplierDuration); -> This line will run our MultiplierActivate() function to turn on our multiplier effect.
     */
    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Ball")
        {
            if (boost)
            {
                col.gameObject.GetComponent<Rigidbody>().AddForce(new Vector3(paddleBoost, paddleBoost, 0));
                Instantiate(boostNotification, this.gameObject.transform.position, Quaternion.identity);
                gm.MultiplierActivate(multiplierDuration);
            }
        }
    }

    void ResetBoost()
    {
        boost = false;
        rend.material.color = Color.yellow;
    }

    /*
     * Update()
     *      Update is called once per frame
     *      if (Input.GetKeyDown (KeyCode.Space) && !boost) -> If the spacebar is pressed down and the boost is NOT true (boost=false).
     *      Invoke("ResetBoost", 1f); -> Invokes the “ResetBoost” function.
     *      rend.material.color = Color.green;-> Set the material color to be green.   
     */
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) && !boost)
        {
            boost = true;
            Invoke("ResetBoost", 1f);
            rend.material.color = Color.green;
        }
    }
}
