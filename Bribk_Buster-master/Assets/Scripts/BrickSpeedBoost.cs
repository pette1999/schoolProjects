using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BrickSpeedBoost : Brick
{
    public float speedBoost = 15;

    /*
     * OnCollisionEnter(Collision other)
     *      public override void OnCollisionEnter (Collision other) -> Here we override our base classes OnCollisionEnter function. This means instead of it using our bases definition of this function, we will use the one we create here.
     *      public class BrickSpeedBoost : Brick -> We are using “Brick” as our base class here we are inheriting from.
     *      public float speedBoost = 15; Here we create a float to hold a “boost” we will add to our ball to speed it up. We use this float to increment the X and Y values of the ball’s speed.
     *      gm.DestroyBrick (); -> Here we are able to use our base classes GameManager gm variable since we inherited it from the “Brick” class.
     *      Vector3 newSpeed; -> Here we are creating a new Vector3 variable that is local to the OnCollisionEnter function. We will use this to update the x and y values so we can add force to these when we AddForce to our ball GameObject.
     *      newSpeed = other.gameObject.GetComponent<Rigidbody> ().velocity; -> Here is where we set the initial value of our “newSpeed” variable.
     *      newSpeed.y = +speedBoost; -> Here we are adding our speed boost to the newSpeed x and y values, respectively.
     *      other.gameObject.GetComponent<Rigidbody> ().AddForce(newSpeed); -> Here we update the velocity of our Rigidbody (ball GameObject) to add the newSpeed variable we created and added to above.
     */
    public override void OnCollisionEnter(Collision other)
    {
        Instantiate(brickDestroyParticle, transform.position, Quaternion.identity);
        gm.DestroyBrick();

        Vector3 newSpeed;
        newSpeed = other.gameObject.GetComponent<Rigidbody>().velocity;
        newSpeed.x += speedBoost;
        newSpeed.y += speedBoost;
        other.gameObject.GetComponent<Rigidbody>().AddForce(newSpeed);
        Destroy(gameObject);
    }
}
