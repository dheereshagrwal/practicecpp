
using System;
using System.Collections.Generic;
namespace College
{

    namespace student
    {
        class Student
        {
            public string Name;
            public string ID;
        }
        namespace department
        {
            public class Department
            {
                public int nstudents;
                public string Name;
                public List<string> Names = new List<string>(){
    "System Design",
    "Computer Science",
    "Mathematics"
    };
            }
            namespace faculty
            {
                public class Faculty
                {
                    public string Name;
                    public List<string> Names = new List<string>(){
    "Engineering",
    "Business",
    "Art"
    };
                    public string University;
                    public string Campus;
                    public string Description;


                }
            }

        }
    }


}



class myMain
{
    static void Main()
    {

        College.student.Student st = new College.student.Student();
        st.Name = "Jake Paul";
        st.ID = "7462CS";
        // College.student.Student.Department stD =
        //   new College.student.Student.Department ();
        // College.student.Student.Department.Faculty stDF =
        //   new College.student.Student.Department.Faculty ();
        // stD.Name = stD.Names[0];
        // stDF.Name = stDF.Names[0];
        // Console.WriteLine (stDF.Name);
        // stD.nstudents = 32;
        // stDF.University = "Stanford";
        // stDF.Campus = "Los Angeles";
    }
}
