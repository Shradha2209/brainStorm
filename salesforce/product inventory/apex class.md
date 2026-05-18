public class ProductInventoryController {

    public Product_Inventory__c product { get; set; }
    public List<Product_Inventory__c> productList { get; set; }

    public ProductInventoryController() {
        product = new Product_Inventory__c();
        loadProducts();
    }

    public PageReference saveProduct() {
        insert product;
        product = new Product_Inventory__c();
        loadProducts();
        return null;
    }

    public void loadProducts() {
        productList = [
            SELECT Id, Name, Serial_No__c,
                   Manufacture_Date__c, Expiry_Date__c
            FROM Product_Inventory__c
            ORDER BY CreatedDate DESC
        ];
    }
}
