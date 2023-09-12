#!/usr/bin/python3

balance = 4000
pin = 2727

users_pin = int(input("Please Enter The 4 digit pin: "))
if users_pin == pin:
    print(f"Your current balance is: ${balance} ")

    users_choice = int(input("Do you want to deposit or withdraw funds?\nEnter 1 to deposit or 2 to withdraw: "))
    users_amount = int(input("Enter the amount for deposit/withdrawal: "))
    if users_choice == 1:
        balance += users_amount
    elif users_choice == 2:
        balance -= users_amount
    print(f"All done! Your updated balance is now: ${balance}")
else:
    print("Incorrect pin entered, Please try again later")
