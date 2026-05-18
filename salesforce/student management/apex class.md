public class StudentController {

    // Object used to bind data from the Visualforce form
    public Student__c student { get; set; }

    // List used to display all student records
    public List<Student__c> studentList { get; set; }

    // Constructor
    public StudentController() {
        student = new Student__c();
        loadStudents();
    }

    // Save the student record
    public PageReference saveStudent() {
        insert student;
        student = new Student__c();   // Clear the form
        loadStudents();               // Refresh the table
        return null;
    }

    // Load all student records
    public void loadStudents() {
        studentList = [
            SELECT Id, Name, Roll_No__c, Class__c, Mobile_No__c
            FROM Student__c
            ORDER BY CreatedDate DESC
        ];
    }
}



