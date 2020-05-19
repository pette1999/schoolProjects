#include <iostream>
#include "Database.h"

using namespace std;

Database::Database()
{
    ifstream readStudent("studentTable.txt"); //read the file
    if (!readStudent)
    {
        cout << " studentTable does not exist. " << endl; //if the file does not exist, set hasFile to false
        hasStudentTable = false;
    }

    ifstream reaadFaculty("facultyTable.txt"); //read the file
    if (!reaadFaculty)
    {
        cout << " facultyTable does not exist. " << endl; //if the file does not exist, set hasFile to false
        hasFacultyTable = false;
    }

    ofstream writeStudent;
    ofstream writeFaculty;
}

Database::~Database()
{

}

void Database::unStudentSerialize()
{
    if(hasStudentTable)
    {
        readStudent.open("studentTable.txt");

        BST<Student> studentTree;

        readStudent.read((char *)&studentTree, sizeof(studentTree));
    }
    else
    {
        cout << "No records in the database" << endl;
    }
}

void Database::StudentSerialize(BST<Student> tree)
{
    if(tree.isEmpty() == false)
    {
        // Opening file in append mode
        writeStudent.open("studentTable.txt", ios::app);

        //BST<Student> studentTree = tree;
        writeStudent.write((char *)&tree, sizeof(tree));
    }
}

void Database::unFacultySerialize()
{
    if (hasFacultyTable)
    {
        readStudent.open("facultyTable.txt");

        BST<Faculty> facultyTree;

        reaadFaculty.read((char *)&facultyTree, sizeof(facultyTree));
    }
    else
    {
        cout << "No records in the database" << endl;
    }
}

void Database::FacultySerialize(BST<Faculty> tree)
{
    if (tree.isEmpty() == false)
    {
        // Opening file in append mode
        writeFaculty.open("facultyTable.txt", ios::app);

        //BST<Student> studentTree = tree;
        writeFaculty.write((char *)&tree, sizeof(tree));
    }
}

void Database::recStudentPrint(TreeNode<Student> *node)
{
    if (node == NULL)
    {
        return;
    }

    recStudentPrint(node->left);
    cout << "ID: " << (node->key).getStudentId() << " ";
    cout << "Name: " << (node->key).getStudentName() << " ";
    cout << "Level: " << (node->key).getStudentLevel() << " ";
    cout << "Major: " << (node->key).getStudentMajor() << " ";
    cout << "GPA: " << (node->key).getStudentGpa() << " ";
    cout << "Advisor: " << (node->key).getStudentAdvisor() << " " << endl;
    recStudentPrint(node->right);
}

void Database::printAllStudents()
{
    recStudentPrint(studentTree.root);
}

void Database::recFacultyPrint(TreeNode<Faculty> *node)
{
    if (node == NULL)
    {
        return;
    }

    recFacultyPrint(node->left);
    cout << "ID: " << (node->key).getFacultyId() << " ";
    cout << "Name: " << (node->key).getFacultyName() << " ";
    cout << "Level: " << (node->key).getFacultyLevel() << " ";
    cout << "Department: " << (node->key).getFacultyDepartment() << " ";
    cout << "Advisee: ";
    (node->key).getFacultyAdvisee();
    cout << " " << endl;

    recFacultyPrint(node->right);
}

void Database::printAllFaculty()
{
    recFacultyPrint(facultyTree.root);
}

void Database::printStudent(Student student)
{
    cout << "ID: " << student.getStudentId() << " ";
    cout << "Name: " << student.getStudentName() << " ";
    cout << "Level: " << student.getStudentLevel() << " ";
    cout << "Major: " << student.getStudentMajor() << " ";
    cout << "GPA: " << student.getStudentGpa() << " ";
    cout << "Advisor: " << student.getStudentAdvisor() << " " << endl;
}

void Database::printFaculty(Faculty faculty)
{
    cout << "ID: " << faculty.getFacultyId() << " ";
    cout << "Name: " << faculty.getFacultyName() << " ";
    cout << "Level: " << faculty.getFacultyLevel() << " ";
    cout << "Department: " << faculty.getFacultyDepartment() << " ";
    cout << "Advisee: ";
    faculty.getFacultyAdvisee();
    cout << " " << endl;
}

void Database::findStudent(int id)
{
    Student student(id);
    if(studentTree.search(student))
    {
        Student student2 = *studentTree.values;
        printStudent(student2);
    }
    else
    {
        cout << "No such student. " << endl;
    }
    
}

void Database::findFaculty(int id)
{
    Faculty faculty(id);
    if(facultyTree.search(faculty))
    {
        Faculty faculty2 = *facultyTree.values;
        printFaculty(faculty2);
    }
    else
    {
        cout << "No such faculty. " << endl;
    }
}

void Database::findStudentAdvisor(int id)
{
    int advisor = 0;
    Student student(id);
    if (studentTree.search(student))
    {
        Student student2 = *studentTree.values;
        advisor = student2.getStudentAdvisor();
        printFaculty(advisor);
    }
    else
    {
        cout << "No such student. " << endl;
    }
}

void Database::findFacultyadvisees(int id)
{
    Faculty faculty(id);
    if (facultyTree.search(faculty))
    {
        Faculty faculty2 = *facultyTree.values;
        int count = 0;
        DoublyLinkedList<int> temp = faculty2.getList();
        while (count < faculty2.getList().getSize())
        {
            printStudent(temp.returnElement(count));
            count++;
        }
    }
    else
    {
        cout << "No such faculty. " << endl;
    }
}

void Database::addNewStudent(Student student)
{
    studentTree.insert(student);
}

void Database::addNewFaculty(Faculty faculty)
{
    facultyTree.insert(faculty);
}

void Database::deleteStudent(int id)
{
    Student student(id);
    if(studentTree.search(student))
    {
        Student student2 = *studentTree.values;
        removeAdvisee(student2.getStudentId(), student2.getStudentAdvisor());
        studentTree.deleteNode(student2);

        cout << "Student has been deleted. " << endl;
    }
    else
    {
        cout << "No such student. " << endl;
    }
    
}

void Database::deleteFaculty(int id)
{
    Faculty faculty(id);
    if (facultyTree.search(faculty))
    {
        Faculty faculty2 = *facultyTree.values;
        int count = 0;
        DoublyLinkedList<int> temp = faculty2.getList();
        while (count < faculty2.getList().getSize())
        {
            Student student(temp.returnElement(count));
            if (studentTree.search(student))
            {
                Student student2 = *studentTree.values;
                student2.setAdvisor(NULL);
            }
            else
            {
                cout << "No such student. " << endl;
            }
            count++;
        }

        facultyTree.deleteNode(faculty2);
        cout << "Faculty has been deleted. " << endl;
    }
    else
    {
        cout << "No such faculty. " << endl;
    }
}

void Database::changeStudentAdvisor(int stu_id, int fac_id)
{
    Faculty faculty(fac_id);
    if(facultyTree.search(faculty))
    {
        Student student(stu_id);
        if (studentTree.search(student))
        {
            Student student2 = *studentTree.values;
            student2.setAdvisor(fac_id);
        }
        else
        {
            cout << "No such student. " << endl;
        }
    }
    else
    {
        cout << "No such faculty. " << endl;
    }
    
}

void Database::removeAdvisee(int stu_id, int fac_id)
{
    Faculty faculty(fac_id);
    if (facultyTree.search(faculty))
    {
        Faculty faculty2 = *facultyTree.values;
        faculty2.list.remove(stu_id);

        //set student advisor to null
        Student student(stu_id);
        if (studentTree.search(student))
        {
            Student student2 = *studentTree.values;
            student2.setAdvisor(NULL);
        }
        else
        {
            cout << "No such student. " << endl;
        }
    }
    else
    {
        cout << "No such faculty. " << endl;
    }
}

void Database::printMenu()
{
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "Exit" << endl;
}

void Database::start()
{
    unStudentSerialize();
    unFacultySerialize();
    while (true)
    {
        int choice = 0;
        printMenu();
        cin >> choice;

        if(choice == 1)
        {
            printAllStudents();
        }
        else if(choice == 2)
        {
            printAllFaculty();
        }
        else if(choice == 3)
        {
            int studentID = 0;
            cout << "Please input student Id number: ";
            cin >> studentID;
            findStudent(studentID);
        }
        else if(choice == 4)
        {
            int facultyID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> facultyID;
            findFaculty(facultyID);
        }
        else if(choice == 5)
        {
            int studentID = 0;
            cout << "Please input student Id number: ";
            cin >> studentID;
            findStudentAdvisor(studentID);
        }
        else if(choice == 6)
        {
            int facultyID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> facultyID;
            findFacultyadvisees(facultyID);
        }
        else if(choice == 7)
        {
            int student_ID = 0;
            string student_Name = "";
            string student_Level = "";
            string student_Major = "";
            double student_Gpa = 0.0;
            int student_Advisor = 0;

            cout << "Please input student id: ";
            cin >> student_ID;
            cout << "\n";

            cout << "Please input student name: ";
            cin >> student_Name;
            cout << "\n";

            cout << "Please input student level: ";
            cin >> student_Level;
            cout << "\n";

            cout << "Please input student major: ";
            cin >> student_Major;
            cout << "\n";

            cout << "Please input student GPA: ";
            cin >> student_Gpa;
            cout << "\n";

            cout << "Please input student advisor: ";
            cin >> student_Advisor;
            cout << "\n";

            Student student(student_ID, student_Name, student_Level, student_Major, student_Gpa, student_Advisor);
            addNewStudent(student);
        }
        else if(choice == 8)
        {
            int studentID = 0;
            cout << "Please input student Id number: ";
            cin >> studentID;
            deleteStudent(studentID);
        }
        else if(choice == 9)
        {
            int faculty_Id = 0;
            int advisee = 0;
            string faculty_Name = "";
            string faculty_Level = "";
            string faculty_Department = "";
            DoublyLinkedList<int> list;

            cout << "Please input faculty id: ";
            cin >> faculty_Id;
            cout << "\n";

            cout << "Please input faculty name: ";
            cin >> faculty_Name;
            cout << "\n";

            cout << "Please input faculty level: ";
            cin >> faculty_Level;
            cout << "\n";

            cout << "Please input faculty department: ";
            cin >> faculty_Department;
            cout << "\n";
            
            // input advisee
            while(true)
            {
                cout << "please input adisee(type 0 to quit): ";
                cin >> advisee;
                cout << "\n";

                if(advisee != 0)
                {
                    list.insertBack(advisee);
                }
                else
                {
                    break;
                }
            }

            Faculty faculty(faculty_Id, faculty_Name, faculty_Level, faculty_Department, list);
            addNewFaculty(faculty);
        }
        else if(choice == 10)
        {
            int facultyID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> facultyID;
            deleteFaculty(facultyID);
        }
        else if(choice == 11)
        {
            int studentID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> studentID;

            int facultyID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> facultyID;

            changeStudentAdvisor(studentID, facultyID);
        }
        else if(choice == 12)
        {
            int studentID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> studentID;

            int facultyID = 0;
            cout << "Pleae input faculty Id number: ";
            cin >> facultyID;

            removeAdvisee(studentID, facultyID);
        }
        else if(choice == 13)
        {
            StudentSerialize(studentTree);
            FacultySerialize(facultyTree);
            cout << "Thank you, Goodbye. " << endl;
            break;
        }
    }
}