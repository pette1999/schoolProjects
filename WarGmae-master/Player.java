import java.util.LinkedList;

/**
*class Player
*number: stands for player number. It would be either 1 or 2
*each player will have a deck of cards.
*/
public class Player
{
  private int number;
  private LinkedList<Card> players = new LinkedList<Card>();

/**
*Player()
*default constructor would create only one player with 26 cards.
*/
  public Player()
  {
    number = 1;
    for(int i=0; i<26; i++)
    {
      players.add(new Deck().deal());
    }
    for(Card c : players)
    {
      System.out.println(c.getValue());
    }
  }

/**
*Player(int p)
*@param p set the player number
*/
  public Player(int p)
  {
    number = p;
    for(int i=0; i<26; i++)
    {
      players.add(new Deck().deal());
    }
    System.out.println("Player " + number + "'s cards: ");
    for(Card c : players)//print the cards the player holds
    {
      System.out.println(c.getValue());
    }
    System.out.println("=====");
  }

/**
*flip()
*removes	and	returns	the	card at the	front	of the list
*/
  public Card flip()
  {
    return players.removeFirst();
  }

/**
*collect(Card c)
*@param c takes a	card as a	parameter	and	adds it to the list of owned	cards
*/
  public void collect(Card c)
  {
    players.addLast(c);
  }

/**
*hasWon()
*check if the player has won the game
*player who win all the cards wins the game
*/
  public boolean hasWon()//check if the player has won the game
  {
    if(players.size() == 52)//player who win all the cards wins the game
    {
      return true;
    }
    else
    {
      return false;
    }
  }

/**
*getNumber()
*@return accessor for the number
*/
  public int getNumber()//accessor for the number
  {
    return number;
  }

/**
*getListLength()
*@return the length of a list(deck)
*/
  public int getListLength()
  {
    return players.size();
  }

/**
*getLastCard()
*@return the last card in the list
*/
  public Card getLastCard()//get the last card in the list
  {
    return players.getLast();
  }

/**
*getList()
*@return the list
*/
  public LinkedList getList()
  {
    return players;
  }


  //for testing while coding
  // public static void main(String[] args)
  // {
  //   Card a = new Card(2,4);
  //   int number = 0;
  //   LinkedList<Card> players = new LinkedList<Card>();
  //
  //   for(int i=0; i<26; i++)
  //   {
  //     players.add(new Deck().deal());
  //   }
  //   for(Card c : players)
  //   {
  //     System.out.println(c.getValue());
  //   }
  //
  //   //System.out.println(players.removeFirst().getValue());
  //
  //   players.addLast(a);
  // }
}
