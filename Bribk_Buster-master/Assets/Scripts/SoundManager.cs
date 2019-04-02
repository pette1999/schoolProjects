using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SoundManager : MonoBehaviour
{
    AudioSource auds;
    public Button Mute;
    public Button unMute;

    // Start is called before the first frame update
    /*
     * Start()
     *      set the mute button is visible
     *      set the inmute button to invisible
     *      play the background music   
     */
    void Start()
    {
        Mute.gameObject.SetActive(true);
        unMute.gameObject.SetActive(false);
        auds = GetComponent<AudioSource>();
    }

    /*
     * PlaySound(AudioClip file)
     *      Play the music.   
     */
    public void PlaySound(AudioClip file)
    {
        auds.PlayOneShot(file);
    }

    //https://answers.unity.com/questions/791088/mute-volume-sound-problem.html
    /*
     * MuteAudio()
     *      set mute button is invisible
     *      set unmute button to visible
     *      set the music volune to 0   
     */
    public void MuteAudio()
    {
        Mute.gameObject.SetActive(false);//https://answers.unity.com/questions/873638/ui-46-canvas-button-how-to-make-it-invisible-on-ga.html
        unMute.gameObject.SetActive(true);
        AudioListener.volume = 0;
    }

    /*
     * unMuteAudio()
     *      set mute button is visible
     *      set unmute button to invisible
     *      set the music volune back to normal   
     */
    public void unMuteAudio()
    {
        unMute.gameObject.SetActive(false);
        Mute.gameObject.SetActive(true);
        AudioListener.volume = 1.0f;
    }
}
