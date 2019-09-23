/**
*  SMTP Mail Program
*  Connects to a TCP Server
*  Waits for a Welcome message from the server
*  Receives a line of input from the keyboard and sends it to the server
*  Receives a response from the server and displays it.
*  Receives a second line of input from the keyboard and sends it to the server
*  Receives a second response from the server and displays it.
*  Closes the socket and exits
*
*  @author: Haifan(Peter) Chen
*  Email:  haichen@chapman.edu
*  Date:  9/11/2019
*  @version: 3.0
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;

class Email
{

  public static void main(String[] argv) throws Exception
  {
    //Create reader to get input from the user
    BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));

    //get input from the user
    System.out.print("Sender Email: ");
    String fromEmail = inFromUser.readLine(); //sender email address

    System.out.print("Recipient Email: ");
    String toEmail = inFromUser.readLine(); //destination address

    System.out.print("Sender Name: ");
    String sender = inFromUser.readLine(); //sender nameSystem.out.println();

    System.out.print("Recipient Name: ");
    String recipient = inFromUser.readLine(); //recipient name

    System.out.print("Subject: ");
    String subject = inFromUser.readLine(); //subject message

    System.out.print("Message: ");
    String actual_message = inFromUser.readLine(); //subject message

    Socket clientSocket = null;

    try
    {
      clientSocket = new Socket("smtp.chapman.edu", 25);
    }
    catch (Exception e)
    {
      System.out.println("Failed to open socket connection");
      System.exit(0);
    }

    //create the network reader and writer
    PrintWriter outToServer = new PrintWriter(clientSocket.getOutputStream(),true);
    BufferedReader inFromServer =  new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

    //Get welcome message from server
    String welcomeMessage = inFromServer.readLine();
    System.out.println("FROM SERVER:" + welcomeMessage);

    //Send greeting message to server
    System.out.println("FROM CLIENT: HELO icd.chapman.edu");
    outToServer.println("HELO icd.chapman.edu"); //greeting  message

    //Get response from server:
    String message = inFromServer.readLine();
    System.out.println("FROM SERVER:" + message);

    //Send MAIL FROM message to server
    System.out.println("MAIL FROM: " + fromEmail);
    outToServer.println("MAIL FROM: " + fromEmail); //sender email

    //Get response from server:
    message = inFromServer.readLine();
    System.out.println("FROM SERVER:" + message);

    //Send RCPT TO message to server
    System.out.println("RCPT TO: " + toEmail);
    outToServer.println("RCPT TO: " + toEmail); //recipient email

    //Get response from server:
    message = inFromServer.readLine();
    System.out.println("FROM SERVER:" + message);

    //Send DATA to SERVER
    System.out.println("DATA");
    outToServer.println("DATA"); //DATA

    //Get response from server:
    message = inFromServer.readLine();
    System.out.println("FROM SERVER:" + message);

    //send sender name, recipient name as well as subject message
    System.out.println("From: " + sender);
    outToServer.println("From: " + sender); //sender
    System.out.println("To: " + recipient);
    outToServer.println("To: " + recipient); //Recipient
    System.out.println("Subject: " + subject);
    outToServer.println("Subject: " + subject); //subject message
    System.out.println(actual_message);
    outToServer.println(actual_message); //message
    System.out.println(".");
    outToServer.println("."); //end DATA

    //Get response from server:
    message = inFromServer.readLine();
    System.out.println("FROM SERVER:" + message);

    //QUIT
    System.out.println("QUIT");
    outToServer.println("QUIT"); //QUIT

    //Get response from server:
    message = inFromServer.readLine();
    System.out.println("FROM SERVER:" + message);

    clientSocket.close();
  }
}
