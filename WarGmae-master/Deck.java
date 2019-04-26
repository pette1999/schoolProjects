/**
*import linkedlist
*import math.random
*/
import java.util.LinkedList;
import java.util.Random;

/**
*class Deck
*create a deck of cards.
*/
public class Deck
{
  private LinkedList<Card> cards = new LinkedList<Card>();

/**
*Deck()
*add four different type pf suit and 13 different type of cars to the deck.
*/
  public Deck()
  {
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<13;j++)
      {
        cards.addFirst(new Card(i,j));
      }
    }
  }

  /**
  *deal()
  *when there is a deal, the deck would drop a andom card and return the card.
  *get a random number from 0 to length of the LinkedList
  */
  public Card deal()
  {
    Random random = new Random();
    int r = (int)(Math.random()*(cards.size()-1));
    cards.remove(r);

    return cards.get(r);
  }



  //for testing while coding
  // public static void main(String[] args)
  // {
  //   LinkedList<Card> cards = new LinkedList<Card>();
  //   int count = 0;
  //
  //   for(int i=0;i<4;i++)
  //   {
  //     for(int j=0;j<13;j++)
  //     {
  //       cards.addFirst(new Card(i,j));
  //       count++;
  //     }
  //   }
  //
  //   for(Card c : cards)
  //   {
  //     System.out.println(c);
  //   }
  //   System.out.println(count);
  //
  //   int a = cards.get(10).getValue();
  //   int b = cards.get(9).getValue();
  //
  //   if(a > b)
  //   {
  //     System.out.println("Yes");
  //   }
  //   else
  //   {
  //     System.out.println("No");
  //   }
  //
  //   Random random = new Random();
  //   int r = (int)(Math.random()*(cards.size()-1));
  //   System.out.println(r);
  //   System.out.println(cards.get(r));
  //   System.out.println("return card: " + cards.get(r).getSuit() + " " + cards.get(r).getValue());
  //   cards.remove(r);
  //   System.out.println(r);
  //   System.out.println(cards.get(r));
  //   System.out.println("current card: " + cards.get(r).getSuit() + " " + cards.get(r).getValue());
  //   System.out.println(cards.size());
  // }
}
