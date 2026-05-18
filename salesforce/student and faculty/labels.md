1. Student Object

a.Custom Object
Property	             Value
Label	               Student
Plural Label	       Students
Record Name       	Student Name
Data Type	           Text



b.Fields
Field Label	       Data Type
Roll_Number	       Number	
Marks	            Number	
Email	           Email	


c.Student Validation Rules

1.Student Name Validation

Formula
ISBLANK(Name)

Error Message
Student name cannot be blank.

2.Roll Number Validation

Formula
Roll_Number__c <= 0

Error Message
Roll number must be greater than 0.

3.Marks Validation

Formula
OR(
    Marks__c < 0,
    Marks__c > 100
)

Error Message
Marks should be between 0 and 100.

4.Email Validation

Formula
NOT(CONTAINS(Email__c, "@"))

Error Message
Ensure the email contains @ symbol.


2. Faculty Object
   
a.Custom Object
Property           	Value
Label	              Faculty
Plural Label	     Faculties
Record Name	       Faculty Name
Data Type	          Text



b.Fields
Field Label	            Data Type	
Faculty_ID	            Number	and unique
Salary	                Currency	
Email	                  Email	
Department	           Text (or Picklist)
Joining_Date          	Date


c.Faculty Validation Rules

1.Faculty Name Validation

Formula
LEN(Name) < 3

Error Message
Faculty Name must contain at least 3 characters.

2.Faculty ID Validation

Formula
Faculty_ID__c <= 0

Error Message
Faculty ID must be greater than 0.

3.Salary Validation

Formula
OR(
    Salary__c < 10000,
    Salary__c > 500000
)

Error Message
Salary must be between 10,000 and 500,000.

4.Email Validation

Formula
NOT(CONTAINS(Email__c, "@"))

Error Message
Ensure the email contains @ symbol.

5.Department Validation

Formula
ISBLANK(Department__c)

Error Message
Department must be selected.

6.Joining Date Validation

Formula
Joining_Date__c > TODAY()

Error Message
Joining Date cannot be a future date.



4.Create Tabs

Create tabs for both objects:

Setup → Tabs
Custom Object Tabs → New
Select:
Student
Faculty
Save




5.Test
Click the App Launcher (9 dots)
Open Students tab.
Click New.
validate


Click the App Launcher (9 dots)
Open Faculty tab.
Click New.
validate
