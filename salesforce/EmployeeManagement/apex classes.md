public class EmployeeManagementSystem {

    // Method to insert a sample employee record
    public static void addEmployee() {
        Employee__c emp = new Employee__c();
        emp.Name = 'Rahul Sharma';          // Emp Name
        emp.Emp_ID__c = 101;
        emp.Email__c = 'rahul@example.com';
        emp.Birth_Date__c = Date.newInstance(1995, 5, 15);
        emp.Department__c = 'IT';

        insert emp;
        System.debug('Employee record inserted successfully.');
    }

    // Method to display all employee records
    public static void displayEmployees() {
        List<Employee__c> empList = [
            SELECT Name, Emp_ID__c, Email__c,
                   Birth_Date__c, Department__c
            FROM Employee__c
            ORDER BY CreatedDate DESC
        ];

        for (Employee__c emp : empList) {
            System.debug(
                'Emp ID: ' + emp.Emp_ID__c +
                ', Name: ' + emp.Name +
                ', Email: ' + emp.Email__c +
                ', Birth Date: ' + emp.Birth_Date__c +
                ', Department: ' + emp.Department__c
            );
        }
    }
}
