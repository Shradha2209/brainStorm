<apex:page controller="EmailController">
    <apex:form>
        <apex:pageBlock title="Send Email Notification">

            <apex:pageBlockSection columns="1">
                <apex:inputText value="{!toAddress}" label="Recipient Email"/>
                <apex:inputText value="{!subject}" label="Subject"/>
                <apex:inputTextarea value="{!body}"
                                    label="Message Body"
                                    rows="5"
                                    cols="50"/>
            </apex:pageBlockSection>

            <apex:pageBlockButtons>
                <apex:commandButton value="Send Email"
                                    action="{!sendEmail}"
                                    rerender="msg"/>
            </apex:pageBlockButtons>

            <apex:outputPanel id="msg">
                <apex:outputText value="{!message}"
                                 style="font-weight:bold;color:green;"/>
            </apex:outputPanel>

        </apex:pageBlock>
    </apex:form>
</apex:page>
