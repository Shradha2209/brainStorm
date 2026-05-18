<!---Label     	Student Page--->
<!---Name	     StudentPage--->

<apex:page controller="StudentController">
    <apex:form>
        <apex:pageBlock title="Student Record Management System">

            <!-- Input Form -->
            <apex:pageBlockSection columns="2">
                <apex:inputField value="{!student.Name}"/>
                <apex:inputField value="{!student.Roll_No__c}"/>
                <apex:inputField value="{!student.Class__c}"/>
                <apex:inputField value="{!student.Mobile_No__c}"/>
            </apex:pageBlockSection>

            <!-- Save Button -->
            <apex:pageBlockButtons>
                <apex:commandButton value="Save Student"
                                    action="{!saveStudent}"
                                    rerender="studentTable"/>
            </apex:pageBlockButtons>

            <!-- Display Student Records -->
            <apex:pageBlockTable value="{!studentList}"
                                 var="s"
                                 id="studentTable">
                <apex:column value="{!s.Name}" headerValue="Student Name"/>
                <apex:column value="{!s.Roll_No__c}" headerValue="Roll No"/>
                <apex:column value="{!s.Class__c}" headerValue="Class"/>
                <apex:column value="{!s.Mobile_No__c}" headerValue="Mobile No"/>
            </apex:pageBlockTable>

        </apex:pageBlock>
    </apex:form>
</apex:page>
