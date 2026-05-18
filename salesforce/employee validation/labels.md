1.Object Details
Property           	Value
Label	             Employee
Plural Label	     Employees
Record Name	      Employee Name
Data Type	         Text

2.Custom Fields to Create
Field Label	            Data Type
Employee_ID           	Number	and unique
Salary	                Currency	
Email	                  Email
Department	            Picklist	
Joining_Date	         Date


3.Department Picklist Values

Add these sample values:

IT
HR
Finance
Sales
Marketing




4.Create Validation Rules

Go to:

Setup → Object Manager → Employee → Validation Rules → New





5.1️⃣ Employee Name Validation
Rule Name
Employee_Name_Validation

Formula
LEN(Name) < 3

Error Message
Employee Name must contain at least 3 characters.

2️⃣ Employee ID Validation
Rule Name
Employee_ID_Validation

Formula
Emp_ID__c <= 0

Error Message
Employee ID must be greater than 0

3️⃣ Salary Validation
Rule Name
Salary_Validation

Formula
OR(
    Salary__c < 10000,
    Salary__c > 500000
)

Error Message
Salary must be between 10,000 and 500,000.

4️⃣ Email Validation
Rule Name
Email_Validation

Formula
NOT(CONTAINS(Email__c, "@"))

Error Message
Please enter a valid email address.

5️⃣ Department Validation
Rule Name
Department_Validation

Formula
ISBLANK(Department__c)

Error Message
Department must be selected.

6️⃣ Joining Date Validation
Rule Name
Joining_Date_Validation

Formula
Joining_Date__c > TODAY()

Error Message
Joining Date cannot be a future date.







6.Create a Custom Tab

If not already created:

Setup → Tabs → New → Custom Object Tab → Employee → Save



7.Create Lightning App Page
Setup → Lightning App Builder
Click New
Select App Page
Label: Employee Management
Choose One Region
Click Done




8.Drag the Related List/Object Component

From the left panel, drag:

Record Form, or
Object Home, or
List View

onto the page.



9.Save and Activate
Click Save
Click Activate
Choose App Default
Click Skip and Save



10.Test
Click the App Launcher (9 dots)
Search Employee
Click New
Enter data
