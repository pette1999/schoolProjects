//reference:https://www.dreamincode.net/forums/topic/116864-how-to-make-a-poker-game-in-java/
/**
*class Card
*define the cards
*/
public class Card
{
  private String suit;
  private int value;
  private String[] suits = {"hearts","spaces","clubs","diamonds"};
  private String[] values = {"3","4","5","6","7","8","9","10","J","Q","K","A","2"};

/**
*Card()
*default constructor
*/
  public Card()
  {
    suit = "";
    value = -1;
  }

  /**
  *Card(int s,int v)
  *override constructor
  */
  public Card(int s,int v)
  {
    suit = suits[s];
    value = v+3;//the card starts from value 3 and J represents 11, Q represents 12, K represents 13 and 2 represents 14. Easy to cpmpare the letter cards with number value.
  }

  /**
  *getSuit()
  *accessor for the Suit
  *@return suit
  */
  public String getSuit()
  {
    return suit;
  }

  /**
  *getValue()
  *accessor for the Suit
  *@return value
  */
  public int getValue()//accessor for the value.
  {
    return value;
  }
}
