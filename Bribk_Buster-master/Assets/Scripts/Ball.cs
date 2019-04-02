using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    public float ballStartVelocity = 300f;
    private Rigidbody rb;
    private bool ballInPlay;
    public float currentVelocity;
    public float speedUpInterval = 5f;
    private bool speedUpActivate;

    /*
     * Awake()
     *      It allows us to access the rigidbody by assigning the private rigidbody variable to equal the one that is on the gameObject currently.
     */
    void Awake()
    {
        rb = GetComponent<Rigidbody>();//It allows us to access the rigidbody by assigning the private rigidbody variable to equal the one that is on the gameObject currently.
    }

    /*Update is called once per frame
     * It sets the transform to be null. This is because we will child the ball to the paddle so it moves with the paddle until it is launched.
     * ballInPlay allows us to track if the player has launched the ball or not, and isKinematic being turned to false allows the ball to be influenced by the physics engine. 
     * We add force to the gameObject’s rigidbody component to get it moving, using the value we declared in the ballStartVelocity variable.   
     */
    void Update()
    {
        if (Input.GetButtonDown("Fire1") && ballInPlay == false)
        {
            transform.parent = null;
            ballInPlay = true;
            rb.isKinematic = false;
            ResetVelocity();
        }
        if (ballInPlay)
        {
            currentVelocity = rb.velocity.sqrMagnitude;
            if (currentVelocity <= 1 && !speedUpActivate)
            {
                ResetVelocity();
            }
        }
    }

    public void ResetVelocity()
    {
        rb.AddForce(new Vector3(ballStartVelocity, ballStartVelocity, 0));
        speedUpActivate = true;
        Invoke("ResetSpeedUpDelay", speedUpInterval);
    }

    public void ResetSpeedUpDelay()
    {
        speedUpActivate = false;
        currentVelocity = rb.velocity.sqrMagnitude;
    }
}
