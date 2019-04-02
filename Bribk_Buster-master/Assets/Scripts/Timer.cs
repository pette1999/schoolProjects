using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public Text timerText;
    private float secondsCount = 0.0f;
    private int minuteCount = 0;
    private int hourCount = 0;

    /*
     * Update()
     *      Update is called once per frame
     *      To show the time. 
     */
    void Update()
    {
        UpdateTimerUI();
    }

    //https://answers.unity.com/questions/64498/time-counter-up.html
    /*
     * UpdateTimerUI()
     *      Update time by time like a clock.   
     */
    public void UpdateTimerUI()
    {
        //set timer UI
        secondsCount += Time.deltaTime;
        timerText.text = "In Game Time: " + hourCount + "h:" + minuteCount + "m:" + (int)secondsCount + "s";
        if (secondsCount >= 60)
        {
            minuteCount++;
            secondsCount = 0;
        }
        else if (minuteCount >= 60)
        {
            hourCount++;
            minuteCount = 0;
        }
    }
}