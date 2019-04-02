using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MaterialFlash : MonoBehaviour
{
    public float resetDelay = 1f;//Exposed in the editor, this will control how long until the material is reset to it’s original value
    private Renderer rend;//This will hold the reference to our GameObject’s renderer component. We need access to this to update the material and color, as they are both part of the Renderer component. It’s set to private so it won’t be displayed in the Inspector.
    private Color originalColor;//This will hold the original color our material started with. Private so it cannot be changed in the Inspector.

    /*
     * Start()
     *      Start is called before the first frame update
     *      We are setting our “rend” variable to be equal to our GameObject’s Renderer component.   
     *      We save our original material color here. This allows us to access it later to reset it back to this color.
     */
    void Start()
    {
        rend = GetComponent<Renderer>();
        originalColor = rend.material.color;
    }

    /*
     * ResetMaterial()
     *      Reset our material back to our originalColor we stored when our object’s Start() function ran.   
     */
    void ResetMaterial()
    {
        rend.material.color = originalColor;
    }

    /*
     * OnCollisionEnter(Collision col)
     *      Parameter Collision col: when there is a collision
     *      If the tag of the GameObject that collides with us is “Ball”, then we run the code inside our if statement.
     *      Set our color to be red.
     *      Use the Invoke function to call a function by stringName and set it delay as a float. Here we use our public resetDelay, that is also exposed in our editor, making it easy to tweak this value.
     */
    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Ball")
        {
            rend.material.color = Color.red;
            Invoke("ResetMaterial", resetDelay);
        }
    }
}
