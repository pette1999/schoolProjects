#include <iostream>
#include <fstream>
#include <sstream>
#include "BST.h"

using namespace std;

class Database
{
public:
    Database();
    ~Database();

    ifstream readStudent;
    ifstream reaadFaculty;
    ofstream writeStudent;
    ofstream writeFaculty;

    bool hasStudentTable;
    bool hasFacultyTable;

    // typedef BST<Student> studentTree;
    // studentTree studentTree;
    // typedef BST<Faculty> facultyTree;
    // facultyTree facultyTree;

    BST<Student> studentTree;
    BST<Faculty> facultyTree;

    string line;

    void StudentSerialize(BST<Student> tree);
    void unStudentSerialize();
    void FacultySerialize(BST<Faculty> tree);
    void unFacultySerialize();

    void recStudentPrint(TreeNode<Student> *node);
    void recFacultyPrint(TreeNode<Faculty> *node);

    void printStudent(Student student);
    void printFaculty(Faculty faculty);
    void printAllStudents();
    void printAllFaculty();
    void findStudent(int id);
    void findFaculty(int id);
    void findStudentAdvisor(int id);
    void findFacultyadvisees(int id);

    void addNewStudent(Student student);
    void deleteStudent(int id);
    void addNewFaculty(Faculty faculty);
    void deleteFaculty(int id);
    void changeStudentAdvisor(int stu_id, int fac_id);
    void removeAdvisee(int stu_id, int fac_id);
    void rollback();
    void exit();

    void printMenu();
    void start();
};