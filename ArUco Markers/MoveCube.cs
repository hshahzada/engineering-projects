using UnityEngine;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;


public class MoveCube : MonoBehaviour {

    public GameObject cubeTest;
    public TextAsset csvFile;
    public float x;
    public float y;
    public float z;

    void Start()
    { 
        StartCoroutine(waiter());
    }

    IEnumerator waiter()
    {
        StreamReader strReader = new StreamReader("C:\\Users\\Haashim Shahzada\\OneDrive - Ryerson University\\UHN\\PostureCoach\\Aruco Marker Detection\\result.csv");
        bool endOfFile = false;
        while (!endOfFile)
        {
            string dataString = strReader.ReadLine();
            if (dataString == null)
            {
                endOfFile = true;
                break;
            }
            string[] dataValues = dataString.Split(',');
            yield return new WaitForSeconds(1);
            for (int i = 0; i < dataValues.Length; i += 3)
            {
                float.TryParse(dataValues[i], out x);
            }
            for (int i = 1; i < dataValues.Length; i += 3)
            {
                float.TryParse(dataValues[i], out y);
            }
            for (int i = 2; i < dataValues.Length; i += 3)
            {
                float.TryParse(dataValues[i], out z);
            }
        }
    }
      
    void Update()
    {
        cubeTest.transform.eulerAngles = new Vector3(x, y, z);
    }
}
