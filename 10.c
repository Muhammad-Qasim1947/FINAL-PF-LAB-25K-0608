#include <stdio.h>

typedef struct shop {
    char name[20] ;
    float price ;
    int quantity ;
} item ;

void get_info(item inventory[], int size, char category[]) {
    printf("Items in category %s:\n", category);
    for (int i = 0; i < size; i++) {
        if ((strcmp(category, "CHEAP") == 0 && inventory[i].price < 20) ||
            (strcmp(category, "MODERATE") == 0 && inventory[i].price >= 20 && inventory[i].price <= 100) ||
            (strcmp(category, "EXPENSIVE") == 0 && inventory[i].price > 100)) {
            printf("Name: %s, Price: $%.2f, Quantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
    printf("\n");
}

void generate_bill(item item, int qty) {
    printf("Bill for %s:\n", item.name);
    printf("Quantity: %d, Unit Price: $%.2f, Total: $%.2f\n", qty, item.price, item.price * qty);
}


int main(){
    item inventory[8] = {
        {"Pen", 5.0, 10},
        {"Notebook", 15.0, 5},
        {"Headphones", 50.0, 2},
        {"Backpack", 80.0, 3},
        {"Shoes", 120.0, 4},
        {"Jacket", 150.0, 2},
        {"Sunglasses", 25.0, 6},
        {"Watch", 200.0, 1}
    };

    get_info(inventory, 8, "CHEAP");
    get_info(inventory, 8, "MODERATE");
    get_info(inventory, 8, "EXPENSIVE");

    // Example bill
    generate_bill(inventory[2], 1); // Headphones
    return 0;

}