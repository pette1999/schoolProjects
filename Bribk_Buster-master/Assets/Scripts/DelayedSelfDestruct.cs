using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DelayedSelfDestruct : MonoBehaviour
{
    public float delay = 2f;//set the delay for 2 seconds

    /*
     * Start()
     *      Start is called before the first frame update
     *      Particle effects do not destroy themselves by default, to have them destroy themselves after a set amount of time
     */
    void Start()
    {
        Destroy(gameObject, delay);
    }
}
