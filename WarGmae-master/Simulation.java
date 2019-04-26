import java.util.ArrayList;//import array list
import java.util.Collections;//import collection for comparing

/**
*class Simulation
*create new game object
*ave_Battle: average battles
*ave_Wars: average wars
*ave_doubleWars: average double wars
*max_Battle: max battle number
*min_Battle: min battle number
*max_Wars: max war number
*min_Wars: min war number
*/
public class Simulation
{
  private Game name = new Game();//create new game object
  private int gameNum;
  private float ave_Battle;//average battles
  private float ave_Wars;//average wars
  private float ave_doubleWars;//average double wars
  private int max_Battle;//max battle number
  private int min_Battle;//min battle number
  private int max_Wars;//max war number
  private int min_Wars;//min war number

/**
*Simulation()
*default constructor
*/
  public Simulation()
  {
    gameNum = 1;
    ave_Battle = -1.0f;
    ave_Wars = -1.0f;
    ave_doubleWars = -1.0f;
    max_Battle = -1;
    min_Battle = -1;
    max_Wars = -1;
    min_Wars = -1;
  }

/**
*Simulation(int n)
*override contructor
*/
  public Simulation(int n)
  {
    gameNum = n;
    ave_Battle = 0.0f;
    ave_Wars = 0.0f;
    ave_doubleWars = 0.0f;
    max_Battle = 0;
    min_Battle = 0;
    max_Wars = 0;
    min_Wars = 0;
  }

/**
*getGnum()
*@return game number
*/
  public int getGnum()
  {
    return gameNum;
  }

/**
*getAveVattles()
*@return average battles
*/
  public float getAveVattles()
  {
    return ave_Battle;
  }

/**
*getAveWars()
*@return average wars
*/
  public float getAveWars()
  {
    return ave_Wars;
  }

/**
*getAvedoubleWar()
*@return average doubel war number
*/
  public float getAvedoubleWar()
  {
    return ave_doubleWars;
  }

/**
*getMaxBattle()
*@return max battle number
*/
  public int getMaxBattle()
  {
    return max_Battle;
  }

/**
*getMinBattle()
*@return min battle number
*/
  public int getMinBattle()
  {
    return min_Battle;
  }

/**
*getGame()
*@return game object
*/
  public Game getGame()
  {
    return name;
  }

/**
*simulate()
*play the game
*/
  public void simulate()
  {
    name.Play();
  }

/**
*calculate()
*calculate the average and max/min value
*total_Battle = name.getBattle();//each game has a battle number
*total_War = name.getWar();//each game has a war number
*total_doubleWar = name.getDoubleWar();//each game has a double number
*/
  public void calculate()
  {
    int total_Battle = 0;
    int total_War = 0;
    int total_doubleWar = 0;
    for(int j=0; j<this.getGnum(); j++)
    {
      total_Battle = name.getBattle();//each game has a battle number
      total_War = name.getWar();//each game has a war number
      total_doubleWar = name.getDoubleWar();//each game has a double number
    }

    ave_Battle = (float)total_Battle / (this.getGnum());
    ave_Wars = (float)total_War / (this.getGnum());
    ave_doubleWars = (float)total_doubleWar / (this.getGnum());
  }

/**
*report(float a, float b, float c, int d, int e, int f, int g)
*formaye for the report
*@param a Average number of battles per game
*@param b Average number of wars per game
*@param c Average number of double wars per game
*@param d Max number of battles per game
*@param e Min number of battles per game
*@param f Max number of wars per game
*@param g Min number of wars per game
*/
  public void report(float a, float b, float c, int d, int e, int f, int g)
  {
    System.out.println("Average number of battles per game: " + a);
    System.out.println("Average number of wars per game: " + b);
    System.out.println("Average number of double wars per game: " + c);
    System.out.println("Max number of battles per game: " + d);
    System.out.println("Min number of battles per game: " + e);
    System.out.println("Max number of wars per game: " + f);
    System.out.println("Min number of wars per game: " + g);
  }

/**
*main(String[] args)
*the main method
*@param args take in commends
*/
  public static void main(String[] args)
  {
    ArrayList<Integer> battlelist = new ArrayList<Integer>();//arraylist for battles
    ArrayList<Integer> warlist = new ArrayList<Integer>();//arraylist for wars
    float ab = 0.0f;
    float aw = 0.0f;
    float adw = 0.0f;
    int mb = 0;
    int minb = 0;
    int mw = 0;
    int minw = 0;
    String str = args[0];
    for(int i=0; i<Integer.parseInt(str); i++)
    {
      Simulation a = new Simulation(Integer.parseInt(str));
      a.simulate();
      a.calculate();
      battlelist.add(a.getGame().getBattle());
      warlist.add(a.getGame().getWar());
      ab += a.getAveVattles();
      aw += a.getAveWars();
      adw += a.getAvedoubleWar();
      mb = Collections.max(battlelist);//https://www.javacodeexamples.com/find-minimum-maximum-value-in-arraylist/1010
      minb = Collections.min(battlelist);
      mw = Collections.max(warlist);
      minw = Collections.min(warlist);

      //pritn the report in the end
      if(i == Integer.parseInt(str)-1)
      {
        a.report(ab,aw,adw,mb,minb,mw,minw);
      }
    }


    //just for testing
    // System.out.println("Average number of battles per game: " + ab);
    // System.out.println("Average number of wars per game: " + aw);
    // System.out.println("Average number of double wars per game: " + adw);
    // System.out.println("Max number of battles per game: " + mb);
    // System.out.println("Min number of battles per game: " + minb);
    // System.out.println("Max number of wars per game: " + mw);
    // System.out.println("Min number of wars per game: " + minw);
  }
}
