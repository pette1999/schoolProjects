#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int Random()
{
  int r = 0;
  r = rand() % 16 + 1;
  return r;
}

int main(int argc, char *argv[])
{
    srand ( time(NULL) );//to reset rand(), to prevent getting the same random number
    //Declare an input file stream
    ifstream inFile;
    ofstream outFile;
    char c;//each cahr in each string
    string line = "";//declare a string variable for each line of teh file
    string fileName = "";
    bool again = true;

    //to check if the file exists
    if (!inFile)
    {
        cout << "there are some problems.";
        exit(1); //if the file is not there, return an error
    }

    if(argc > 1)
    {
      fileName = argv[1];
      cout << "fileName: " << fileName << endl;
    }

    while(again)
    {
      //hardcode to lower case
      inFile.open(fileName);
      string newStr = "";
      while(getline(inFile, line))//while there is a line in the file
      {
        for (char c : line)
        {
          if(c == 'a')
          {
            newStr += "A";
          }
          else if(c == 't')
          {
            newStr += "T";
          }
          else if(c == 'c')
          {
            newStr += "C";
          }
          else if(c == 'g')
          {
            newStr += "G";
          }
          else
          {
            newStr += c;
          }
        }
        newStr += "\n";
      }

      inFile.close();

      outFile.open(fileName);
      outFile << newStr;
      outFile.close();
      inFile.open(fileName);

      int line_count = 0;//count total lines in a file
      int total_length = 0;//get sum of total lines
      double average_length = 0.0;//the average length of the file string
      double temp_variance = 0.0;//(length - average) square
      double variance = 0.0;
      double standard_deviation = 0.0;

      //https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
      while(getline(inFile, line))//while there is a line in the file
      {
          int str_length = line.length();//get length for each line
          total_length += str_length;
          line_count++;
      }

      inFile.close();//it's the end of the file, so close the file

      average_length = total_length/(double)line_count;//calulate average string length

      //getting variances
      inFile.open(fileName);//reopen the file for a new loop
      while (getline(inFile, line)) //while there is a line in the file
      {
          int str_length = line.length(); //get length for each line
          double temp = ((double)str_length - average_length) * ((double)str_length - average_length);
          temp_variance += temp;
      }

      variance = temp_variance /line_count;//calculate variance of the string
      standard_deviation = sqrt(variance);//calculate the standard deviation

      inFile.close();//cloase the file at the end of the file

      //getting single probability
      inFile.open(fileName); //reopen the file for a new loop
      int count_a;
      int count_c;
      int count_t;
      int count_g;

      while (getline(inFile, line)) //while there is a line in the file
      {
          for (char c : line) //for every char in the line string
          {
              if(c == 'A')
              {
                  count_a++;//the count number plus 1 if there is an a or A
              }
              else if(c == 'a')
              {
                  count_a++;
              }
              else if (c == 'C')
              {
                  count_c++;
              }
              else if (c == 'c')
              {
                  count_c++;
              }
              else if (c == 'T')
              {
                  count_t++;
              }
              else if (c == 't')
              {
                  count_t++;
              }
              else if (c == 'G')
              {
                  count_g++;
              }
              else if (c == 'g')
              {
                  count_g++;
              }
          }
      }

      inFile.close();

      //getting double probability
      inFile.open(fileName);       //reopen the file for a new loop
      int total_pair;
      int count_aa;
      int count_at;
      int count_ac;
      int count_ag;
      int count_ta;
      int count_tt;
      int count_tc;
      int count_tg;
      int count_ca;
      int count_ct;
      int count_cc;
      int count_cg;
      int count_ga;
      int count_gt;
      int count_gc;
      int count_gg;

      while (getline(inFile, line)) //while there is a line in the file
      {
          int str_length = line.length(); //get length for each line
          total_pair += str_length/2;
          if(str_length%2 == 1)
          {
              line = line.substr(0,str_length-1);
          }
          for(int i=0 ; i<line.length()-1; i+=2)
          {
              char c = line[i];
              if(c == 'A')//A
              {
                  if(line[i+1] == 'A')
                  {
                      count_aa++;
                  }
                  else if(line[i+1] == 'T')
                  {
                      count_at++;
                  }
                  else if (line[i+1] == 'C')
                  {
                      count_ac++;
                  }
                  else if (line[i+1] == 'G')
                  {
                      count_ag++;
                  }
              }
              else if(c == 'T')//T
              {
                  if (line[i + 1] == 'A')
                  {
                      count_ta++;
                  }
                  else if (line[i + 1] == 'T')
                  {
                      count_tt++;
                  }
                  else if (line[i + 1] == 'C')
                  {
                      count_tc++;
                  }
                  else if (line[i + 1] == 'G')
                  {
                      count_tg++;
                  }
              }
              else if (c == 'C') //C
              {
                  if (line[i + 1] == 'A')
                  {
                      count_ca++;
                  }
                  else if (line[i + 1] == 'T')
                  {
                      count_ct++;
                  }
                  else if (line[i + 1] == 'C')
                  {
                      count_cc++;
                  }
                  else if (line[i + 1] == 'G')
                  {
                      count_cg++;
                  }
              }
              else if (c == 'G') //G
              {
                  if (line[i + 1] == 'A')
                  {
                      count_ga++;
                  }
                  else if (line[i + 1] == 'T')
                  {
                      count_gt++;
                  }
                  else if (line[i + 1] == 'C')
                  {
                      count_gc++;
                  }
                  else if (line[i + 1] == 'G')
                  {
                      count_gg++;
                  }
              }
          }
      }

      //print out the analysis
      cout << "Total length: " << total_length << endl;
      cout << "Average length: " << average_length << endl;
      cout << "Variance: " << variance << endl;
      cout << "Standard Deviation: " << standard_deviation << endl;

      cout << "Probability of A: " << count_a/(double)total_length*100 << "%" << endl;
      cout << "Probability of T: " << count_t / (double)total_length * 100 << "%" << endl;
      cout << "Probability of C: " << count_c / (double)total_length * 100 << "%" << endl;
      cout << "Probability of G: " << count_g / (double)total_length * 100 << "%" << endl;

      cout << "Probability of AA: " << count_aa / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of AC: " << count_ac / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of AT: " << count_at / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of AG: " << count_ag / (double)total_pair * 100 << "%" << endl;

      cout << "Probability of TA: " << count_ta / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of TC: " << count_tc / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of TT: " << count_tt / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of TG: " << count_tg / (double)total_pair * 100 << "%" << endl;

      cout << "Probability of CA: " << count_ca / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of CC: " << count_cc / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of CT: " << count_ct / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of CG: " << count_cg / (double)total_pair * 100 << "%" << endl;

      cout << "Probability of GA: " << count_ga / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of GC: " << count_gc / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of GT: " << count_gt / (double)total_pair * 100 << "%" << endl;
      cout << "Probability of GG: " << count_gg / (double)total_pair * 100 << "%" << endl;
      // close the file stream
      inFile.close();

      //write out to a file
      outFile.open ("PeterChen.out",  fstream::app);
      outFile << "Name: Haifan(Peter) Chen\n";
      outFile << "Student ID: 2326305\n";
      outFile << "Class/section: Data Structure Section 01\n\n";
      outFile << "Sum: " << total_length << "\n";
      outFile << "Mean: " << average_length << "\n";
      outFile << "Variance: " << variance << "\n";
      outFile << "Standard Deviation: " << standard_deviation << "\n\n";

      outFile << "Probability: \n";
      outFile << "Probability of A: " << count_a/(double)total_length*100 << "%" << "\n";
      outFile << "Probability of T: " << count_t/(double)total_length*100 << "%" << "\n";
      outFile << "Probability of C: " << count_c/(double)total_length*100 << "%" << "\n";
      outFile << "Probability of G: " << count_g/(double)total_length*100 << "%" << "\n\n";

      outFile << "Probability of AA: " << count_aa / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of AT: " << count_at / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of AC: " << count_ac / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of AG: " << count_ag / (double)total_pair * 100 << "%" << "\n";

      outFile << "Probability of TA: " << count_ta / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of TT: " << count_tt / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of TC: " << count_tc / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of TG: " << count_tg / (double)total_pair * 100 << "%" << "\n";

      outFile << "Probability of CA: " << count_ca / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of CT: " << count_ct / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of CC: " << count_cc / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of CG: " << count_cg / (double)total_pair * 100 << "%" << "\n";

      outFile << "Probability of GA: " << count_ga / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of GT: " << count_gt / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of GC: " << count_gc / (double)total_pair * 100 << "%" << "\n";
      outFile << "Probability of GG: " << count_gg / (double)total_pair * 100 << "%" << "\n";

      outFile.close();

      double a = 0.0;
      double b = 0.0;
      outFile.open ("Temp.txt");

      double D = 0.0;
      for(int i=0 ; i<1000 ; ++i)
      {
        //Gaussian distribution
        a = rand()/(double)RAND_MAX;
        b = rand()/(double)RAND_MAX;
        double C = sqrt(-2*log(a))*cos(2*M_PI*b);
        D = standard_deviation * C + average_length;
        D = abs(D);
        D = round(D);
        for(int j=0 ; j<D ; ++j)
        {
          outFile << "0";
        }
        outFile << "\n";
      }
      outFile.close();//close the temp file

      //get data from generated Temp file
      inFile.open("Temp.txt");//read the Temp file
      int total_length_temp;
      int line_count_temp;
      int total_pair_temp;
      int actual_temp_length;
      while(getline(inFile, line))//while there is a line in the file
      {
          int str_length = line.length();//get length for each line
          total_length_temp += str_length;
          total_pair_temp += str_length/2;
          actual_temp_length = total_pair_temp * 2;
          line_count_temp++;
      }


      int AA = total_pair_temp * (count_aa / (double)total_pair);
      int AT = total_pair_temp * (count_at / (double)total_pair);
      int AC = total_pair_temp * (count_ac / (double)total_pair);
      int AG = total_pair_temp * (count_ag / (double)total_pair);
      int TA = total_pair_temp * (count_ta / (double)total_pair);
      int TT = total_pair_temp * (count_tt / (double)total_pair);
      int TC = total_pair_temp * (count_tc / (double)total_pair);
      int TG = total_pair_temp * (count_tg / (double)total_pair);
      int CA = total_pair_temp * (count_ca / (double)total_pair);
      int CT = total_pair_temp * (count_ct / (double)total_pair);
      int CC = total_pair_temp * (count_cc / (double)total_pair);
      int CG = total_pair_temp * (count_cg / (double)total_pair);
      int GA = total_pair_temp * (count_ga / (double)total_pair);
      int GT = total_pair_temp * (count_gt / (double)total_pair);
      int GC = total_pair_temp * (count_gc / (double)total_pair);
      int GG = total_pair_temp * (count_gg / (double)total_pair);

      int A = total_length_temp * (count_a/(double)total_length);
      int T = total_length_temp * (count_t/(double)total_length);
      int C = total_length_temp * (count_c/(double)total_length);
      int G = total_length_temp * (count_g/(double)total_length);

      int eA = AA*2+AT+AC+AG+TA+CA+GA;
      int eT = AT+TA+TT*2+TC+TG+CT+GT;
      int eC = AC+TC+CA+CT+CC*2+CG+GC;
      int eG = AG+TG+CG+GA+GT+GC+GG*2;

      cout << "Temp total length: " << total_length_temp << endl;
      cout << "Actual length: " << actual_temp_length << endl;
      cout << "Temp line count: " << line_count_temp << endl;
      cout << "Temp total pair count: " << total_pair_temp << endl;
      cout << "AA: " << AA << endl;
      cout << "AT: " << AT << endl;
      cout << "AC: " << AC << endl;
      cout << "AG: " << AG << endl;
      cout << "TA: " << TA << endl;
      cout << "TT: " << TT << endl;
      cout << "TC: " << TC << endl;
      cout << "TG: " << TG << endl;
      cout << "CA: " << CA << endl;
      cout << "CT: " << CT << endl;
      cout << "CC: " << CC << endl;
      cout << "CG: " << CG << endl;
      cout << "GA: " << GA << endl;
      cout << "GT: " << GT << endl;
      cout << "GC: " << GC << endl;
      cout << "GG: " << GG << endl;

      cout << "A: " << A << endl;
      cout << "T: " << T << endl;
      cout << "C: " << C << endl;
      cout << "G: " << G << endl;

      cout << "eA: " << eA << endl;
      cout << "eT: " << eT << endl;
      cout << "eC: " << eC << endl;
      cout << "eG: " << eG << endl;

      inFile.close();

      //start to do some shit
      inFile.open("Temp.txt");
      string write_to_file = "";
      int linenumber = 0;

      while(getline(inFile, line))
      {
        linenumber += 1;
        int picker_pair = 0;
        int str_length = line.length();
        if(str_length%2 == 1)
        {
          //odd
          int this_line_pair = str_length/2;
          for(int i=0 ; i<this_line_pair ; i++)
          {
            picker_pair = Random();
            cout << "random number: " << picker_pair << endl;
            if(AA==0 && AT==0 && AC==0 && AG==0 && TA==0 && TT==0 && TC==0 && TG==0 && CA==0 && CT==0 && CC==0 && CG==0 && GA==0 && GT==0 && GC==0 && GG==0)
            {
              cout << "Alert: Pairs done" << endl;
              continue;
            }
            else
            {
              if(picker_pair == 1)
              {
                if(AA > 0)
                {
                  write_to_file += "AA";
                  AA -= 1;
                }
                else
                {
                  if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 2)
              {
                if(AT > 0)
                {
                  write_to_file += "AT";
                  AT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 3)
              {
                if(AC > 0)
                {
                  write_to_file += "AC";
                  AC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 4)
              {
                if(AG > 0)
                {
                  write_to_file += "AG";
                  AG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 5)
              {
                if(TA > 0)
                {
                  write_to_file += "TA";
                  TA -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 6)
              {
                if(TT > 0)
                {
                  write_to_file += "TT";
                  TT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 7)
              {
                if(TC > 0)
                {
                  write_to_file += "TC";
                  TC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 8)
              {
                if(TG > 0)
                {
                  write_to_file += "TG";
                  TG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 9)
              {
                if(CA > 0)
                {
                  write_to_file += "CA";
                  CA -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 10)
              {
                if(CT > 0)
                {
                  write_to_file += "CT";
                  CT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 11)
              {
                if(CC > 0)
                {
                  write_to_file += "CC";
                  CC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 12)
              {
                if(CG > 0)
                {
                  write_to_file += "CG";
                  CG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 13)
              {
                if(GA > 0)
                {
                  write_to_file += "GA";
                  GA -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 14)
              {
                if(GT > 0)
                {
                  write_to_file += "GT";
                  GT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 15)
              {
                if(GC > 0)
                {
                  write_to_file += "GC";
                  GC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 16)
              {
                if(GG > 0)
                {
                  write_to_file += "GG";
                  GG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                }
              }
            }
          }

          if(A==0 && T==0 && C==0 && G==0)
          {
            cout << "Alert: single letter done" << endl;
            break;
          }
          else
          {
            if(a >= 0 && a < 0.25)
            {
              if(A > 0)
              {
                write_to_file += "A";
                cout << "hello" << endl;
                A -= 1;
              }
              else
              {
                a = 0.25;
              }
            }
            else if(a >= 0.25 && a < 0.5)
            {
              if(A > 0)
              {
                write_to_file += "T";
                cout << "hello" << endl;
                T -= 1;
              }
              else
              {
                a = 0.5;
              }
            }
            else if(a >= 0.5 && a < 0.75)
            {
              if(A > 0)
              {
                write_to_file += "C";
                cout << "hello" << endl;
                C -= 1;
              }
              else
              {
                a = 0.75;
              }
            }
            else
            {
              if(A > 0)
              {
                write_to_file += "G";
                cout << "hello" << endl;
                G -= 1;
              }
              else
              {
                a = 0.0;
              }
            }
          }
        }
        else
        {
          //even
          picker_pair = Random();
          cout << "random number: " << picker_pair << endl;
          int this_line_pair = str_length/2;
          for(int j=0 ; j<this_line_pair ; j++)
          {
            if(AA==0 && AT==0 && AC==0 && AG==0 && TA==0 && TT==0 && TC==0 && TG==0 && CA==0 && CT==0 && CC==0 && CG==0 && GA==0 && GT==0 && GC==0 && GG==0)
            {
              cout << "Alert: Pairs done" << endl;
              continue;
            }
            else
            {
              if(picker_pair == 1)
              {
                if(AA > 0)
                {
                  write_to_file += "AA";
                  AA -= 1;
                }
                else
                {
                  if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 2)
              {
                if(AT > 0)
                {
                  write_to_file += "AT";
                  AT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 3)
              {
                if(AC > 0)
                {
                  write_to_file += "AC";
                  AC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 4)
              {
                if(AG > 0)
                {
                  write_to_file += "AG";
                  AG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 5)
              {
                if(TA > 0)
                {
                  write_to_file += "TA";
                  TA -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 6)
              {
                if(TT > 0)
                {
                  write_to_file += "TT";
                  TT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 7)
              {
                if(TC > 0)
                {
                  write_to_file += "TC";
                  TC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 8)
              {
                if(TG > 0)
                {
                  write_to_file += "TG";
                  TG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 9)
              {
                if(CA > 0)
                {
                  write_to_file += "CA";
                  CA -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 10)
              {
                if(CT > 0)
                {
                  write_to_file += "CT";
                  CT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 11)
              {
                if(CC > 0)
                {
                  write_to_file += "CC";
                  CC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 12)
              {
                if(CG > 0)
                {
                  write_to_file += "CG";
                  CG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 13)
              {
                if(GA > 0)
                {
                  write_to_file += "GA";
                  GA -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 14)
              {
                if(GT > 0)
                {
                  write_to_file += "GT";
                  GT -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 15)
              {
                if(GC > 0)
                {
                  write_to_file += "GC";
                  GC -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GG > 0)
                  {
                    write_to_file += "GG";
                    GG -= 1;
                  }
                }
              }
              else if(picker_pair == 16)
              {
                if(GG > 0)
                {
                  write_to_file += "GG";
                  GG -= 1;
                }
                else
                {
                  if(AA > 0)
                  {
                    write_to_file += "AA";
                    AA -= 1;
                  }
                  else if(AT > 0)
                  {
                    write_to_file += "AT";
                    AT -= 1;
                  }
                  else if(AC > 0)
                  {
                    write_to_file += "AC";
                    AC -= 1;
                  }
                  else if(AG > 0)
                  {
                    write_to_file += "AG";
                    AG -= 1;
                  }
                  else if(TA > 0)
                  {
                    write_to_file += "TA";
                    TA -= 1;
                  }
                  else if(TT > 0)
                  {
                    write_to_file += "TT";
                    TT -= 1;
                  }
                  else if(TC > 0)
                  {
                    write_to_file += "TC";
                    TC -= 1;
                  }
                  else if(TG > 0)
                  {
                    write_to_file += "TG";
                    TG -= 1;
                  }
                  else if(CA > 0)
                  {
                    write_to_file += "CA";
                    CA -= 1;
                  }
                  else if(CT > 0)
                  {
                    write_to_file += "CT";
                    CT -= 1;
                  }
                  else if(CC > 0)
                  {
                    write_to_file += "CC";
                    CC -= 1;
                  }
                  else if(CG > 0)
                  {
                    write_to_file += "CG";
                    CG -= 1;
                  }
                  else if(GA > 0)
                  {
                    write_to_file += "GA";
                    GA -= 1;
                  }
                  else if(GT > 0)
                  {
                    write_to_file += "GT";
                    GT -= 1;
                  }
                  else if(GC > 0)
                  {
                    write_to_file += "GC";
                    GC -= 1;
                  }
                }
              }
            }
          }
        }
        write_to_file += " ";
        write_to_file += to_string(linenumber);
        write_to_file += "\n";
      }

      inFile.close();
      write_to_file += "\n";
      write_to_file += "-------------------------------------------------------------------------------";
      write_to_file += "\n";
      cout << write_to_file << endl;

      outFile.open("PeterChen.out", fstream::app);
      outFile << "\n";
      outFile << "1000 lines of DNA: \n";
      outFile << write_to_file;

      cout << "Do you want to process another file to have more fun?(Please type 'Y' for yes, 'N' for NO)" << endl;
      string input;

      cin >> input;

      if(input == "Y" || input == "y")
      {
        cout << "Please enter the fileName here: ";
        cin >> fileName;
      }
      else
      {
        cout << "Goodbye, my friend. See you next time. Please give me 100%! I spent 10+ hours on this assignment and got a lot of mental anguish. Please Please Please, Your 100% is my monivatino in this class. By the way, I'm from China, and not good English, so this is the best I can come up. Thak you, bye!" << endl;
        again = false;
        return 0;
      }
    }
}
