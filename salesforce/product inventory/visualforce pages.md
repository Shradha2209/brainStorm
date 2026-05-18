<apex:page controller="ProductInventoryController">
    <apex:form>
        <apex:pageBlock title="Product Inventory Management System">

            <apex:pageBlockSection columns="2">
                <apex:inputField value="{!product.Name}"/>
                <apex:inputField value="{!product.Serial_no__c}"/>
                <apex:inputField value="{!product.Manfacture_date__c}"/>
                <apex:inputField value="{!product.Expiry_date__c}"/>
            </apex:pageBlockSection>

            <apex:pageBlockButtons>
                <apex:commandButton value="Save Product"
                                    action="{!saveProduct}"
                                    rerender="productTable"/>
            </apex:pageBlockButtons>

            <apex:pageBlockTable value="{!productList}"
                                 var="p"
                                 id="productTable">
                <apex:column value="{!p.Name}" headerValue="Product Name"/>
                <apex:column value="{!p.Serial_no__c}" headerValue="Serial No"/>
                <apex:column value="{!p.Manfacture_date__c}" headerValue="Manufacture Date"/>
                <apex:column value="{!p.Expiry_date__c}" headerValue="Expiry Date"/>
            </apex:pageBlockTable>

        </apex:pageBlock>
    </apex:form>
</apex:page>
