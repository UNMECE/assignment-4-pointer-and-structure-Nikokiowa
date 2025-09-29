#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


// Add items to store list
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {

  item_list[index].price = price;

  item_list[index].sku = malloc(strlen(sku) + 1);
  strcpy(item_list[index].sku, sku);

  item_list[index].category = malloc(strlen(category) + 1);
  strcpy(item_list[index].category, category);

  item_list[index].name = malloc(strlen(name) + 1);
  strcpy(item_list[index].name, name);

}


// Free up memory.
void free_items(Item *item_list, int size) {

  for (int i = 0; i < size; i++) {
    free(item_list[i].sku);
    free(item_list[i].category);
    free(item_list[i].name);
  }
  free(item_list);
}


double average_price(Item *item_list, int size) {

  double total = 0.0;
  
  for (int i = 0; i < size; i++) {
    total += item_list[i].price;
  }

  return total/size;

}

// Print items to screen
void print_item(Item *item_list, int size) {

  for (int i = 0; i < size; i++) {
    printf("\n#########################\n");
    printf("Item: %s\n", item_list[i].name);
    printf("Sku: %s\n", item_list[i].sku);
    printf("Price: %f\n", item_list[i].price);
    printf("Category: %s\n", item_list[i].category);
  }
}


int main(int argc, char *argv[]) {

  int size = 5;
  Item *items = malloc(sizeof(Item) * size);

  char response[10];

  // Add items.
  add_item(items, 3.08, "908036", "Dairy", "2% Milk", 0);
  add_item(items, 7.98, "822613", "Beverage", "12pk Coca-Cola", 1);
  add_item(items, 3.50, "611377", "Snack Foods", "Lay's Barbecue Flavored Potato Chips", 2);
  add_item(items, 32.63, "225868", "Meat", "Ribeye Beef Steak", 3);
  add_item(items, 2.34, "102690", "Poultry", "Large White Eggs, 12 Count", 4);


  // Search from command line argument.
  if (argc > 1) {

    char *search_sku = argv[1];
    int ct = 0;

    while (ct < size && strcmp(items[ct].sku, search_sku) != 0) {
      ct++;
    }

    if (ct < size) {
      printf("#################\n");
      printf("Item found with sku: %s\n", search_sku);
      printf("Name: %s\n", items[ct].name);
      printf("Sku: %s\n", items[ct].sku);
      printf("Price: %f\n", items[ct].price);
      printf("Category: %s\n", items[ct].category);
    }
    else {
      printf("Item not found.\n");
    }
  }

  // Ask user if they would like to see the list of items in the program
  printf("Would you like to see the list of items? (yes/no): \n");
  scanf("%s", response);

  // If 'yes' print the items.
  if (strcmp(response, "yes") == 0) {
    print_item(items, size);

    double avg = average_price(items, size);
    printf("\n#########################\n");
    printf("Average of all items: %f\n\n", avg);
  }
  else if (strcmp(response, "Yes") == 0) {
    print_item(items, size);

    double avg = average_price(items, size);
    printf("\n*******************\n");
    printf("Average of all items: %f\n\n", avg);
  }
  else if (strcmp(response, "y") == 0) {
    print_item(items, size);

    double avg = average_price(items, size);
    printf("\n######################\n");
    printf("Average of all items: %f\n\n", avg);
  }
  else if (strcmp(response, "YES") == 0) {
    print_item(items, size);

    double avg = average_price(items, size);
    printf("\n********************\n");
    printf("Average of all items: %f\n\n", avg);
  }
  // If 'no' tell the user goodbye and end the program
  else if (strcmp(response, "no") == 0) {
    printf("Goodbye\n");
    return 0;
  }
  else if (strcmp(response, "No") == 0) {
    printf("Goodbye\n");
    return 0;
  }
  else if (strcmp(response, "n") == 0) {
    printf("Goodbye\n");
    return 0;
  }
  else if(strcmp(response, "NO") == 0) {
    printf("Goodbye\n");
    return 0;
  }
  else {
    printf("Invalid input. Please enter \"yes\" or \"no\".\n");
  }

  free_items(items, size);

  return 0;

}
