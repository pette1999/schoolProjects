using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LevelManager : MonoBehaviour
{
    public int curLevel = 0;
    public GameObject[] levels;
    private GameObject curLevelGO;
    public Text levelUITxt;

    /*
     * ResetLevels()
     *      
     */
    void ResetLevels()
    {
        curLevel = 0;
        LoadNextLevel();
    }

    public void SetLevelUI()
    {
        levelUITxt.text = "Level " + (curLevel);
    }

    /*
     * LoadNextLevel()
     *      We start with a null check to make sure we have a curLevelGO assigned before we attempt to destroy it. If we don’t have one (it’s null), we move on to the rest of our code. If we do have a level loaded, we need to destroy it so we can load the next level.
     *      The next line of code is where we instantiate our next level as a GameObject. We did this with our player’s paddle as well
     *      We add +1 to the current level count variable, curLevel.   
     *      We are creating an if statement here to check a condition: If the curLevel variable is less than levels.length (the total count of levels in our array), we continue to load the next level ELSE we reset the levels with the ResetLevels() function we will create below...
     */
    public void LoadNextLevel()
    {
        if(curLevelGO != null) 
        {
            Destroy(curLevelGO);
        }
        if (curLevel < levels.Length)
        {
            curLevelGO = Instantiate(levels[curLevel], levels[curLevel].transform.position, levels[curLevel].transform.rotation) as GameObject;
            curLevel++;
        }
        else
        {
            ResetLevels();
        }
        SetLevelUI();
    }

}
