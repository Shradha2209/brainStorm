1.Object Details

Label	               Employee
Plural Label	       Employees
Record Name	         Emp Name
Data Type	           Text

2. Custom objects
Field Label            	Data Type
Emp_ID	                 Number
Email	                    Email
Birth_Date	                Date
Department	               Text


3. console

   EmployeeManagementSystem.addEmployee(
    101,
    'Rahul Sharma',
    'rahul@example.com',
    Date.newInstance(1995, 5, 15),
    'IT'
);



EmployeeManagementSystem.displayEmployees();


EmployeeManagementSystem.updateEmployee(101, 'HR');


EmployeeManagementSystem.deleteEmployee(101);
