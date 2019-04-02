using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyBallZone : MonoBehaviour
{
    private GameManager gm;

    /*
     * Awake()
     *      Use GameObject.Find to find the GameManager by name since it is the only object in the scene with this name.
     */
    void Awake()
    {
        gm = GameObject.Find("GameManager").GetComponent<GameManager>();
    }

    /*
     * OnTriggerEnter(Collider col)
     *      Parameter Collider col: when the ball is destoried.
     *      call the GameManager and use its LoseLife() function to decrement a life from the player's total. We will also destroy the gameObject that collides with this script’s GameObject.   
     */
    void OnTriggerEnter(Collider col)
    {
        gm.LoseLife();
        Destroy(col.gameObject);
    }
}
