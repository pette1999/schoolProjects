using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Brick : MonoBehaviour
{
    public GameObject brickDestroyParticle;
    [HideInInspector]public GameManager gm;//[HideInInspector]public GameManager gm; -> Anytime you want to hide variables in the inspector (for example, a variable you want set to be public so other scripts can access it, but don’t want your designer to change it in the inspector), you can add [HideInInspector] so it isn’t displayed.

    /*
     * Awake()
     *      Use GameObject.Find to find the GameManager by name since it is the only object in the scene with this name.
     */
    void Awake()
    {
        gm = GameObject.Find("GameManager").GetComponent<GameManager>();
    }

    /*
     * OnCollosionEnter(Collision other)
     *      Parameter: Collision other, check if there is a collision
     *      instantiate (spawn)
     *      When the ball collides with a brick, it will play the particle effect.   
     *      When the ball hits the brick, it will destroy the brick.
     *      public virtual void -> Here we are changing our function to a “Virtual” method. A virtual function is a member function that you expect to be redefined in derived classes. We will be overriding this later. Also, an important note here is that these classes must be public.
     */
    public virtual void OnCollisionEnter(Collision other)
    {
        Instantiate(brickDestroyParticle, transform.position, Quaternion.identity);
        gm.DestroyBrick();
        Destroy(gameObject);
    }
}
