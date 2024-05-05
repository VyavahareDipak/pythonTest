import random

# Dictionary of responses for different types of user inputs
responses = {
    "greeting": ["Hello! Welcome to our grocery shop.", "Hi there! How can I assist you with your groceries today?", "Hey! What can I help you find?"],
    "farewell": ["Goodbye! Have a great day!", "Thank you for visiting. See you again soon!", "Take care!"],
    "thanks": ["You're welcome!", "No problem!", "My pleasure!"],
    "product": ["We have a wide range of fresh fruits and vegetables.", "Our dairy products are located in aisle 2.", "You can find canned goods in aisle 3.", "Our bakery section offers delicious bread and pastries."],
    "opening_hours": ["We are open from 9:00 AM to 8:00 PM, Monday to Saturday.", "Our store hours are from 8:00 AM to 9:00 PM every day except Sunday.", "We open at 7:00 AM and close at 10:00 PM, Monday through Friday."],
    "location": ["Our grocery shop is located at 123 Main Street.", "You can find us at the corner of Oak Avenue and Maple Street.", "We're situated in the shopping plaza on Elm Street."],
    "default": ["I'm sorry, I didn't understand that.", "Could you please rephrase that?", "I'm not sure what you mean."]
}

# Function to generate responses based on user input
def get_response(user_input):
    if user_input in ["hi", "hello", "hey"]:
        return random.choice(responses["greeting"])
    elif user_input in ["bye", "goodbye"]:
        return random.choice(responses["farewell"])
    elif "thank" in user_input:
        return random.choice(responses["thanks"])
    elif "product" in user_input or "grocery" in user_input:
        return random.choice(responses["products"])
    elif "hours" in user_input or "open" in user_input   or "close" in user_input:
        return random.choice(responses["opening_hours"])
    elif "location" in user_input or "address" in user_input:
        return random.choice(responses["location"])
    else:
        return random.choice(responses["default"])

# Main function to run the chatbot
def main():
    print("Welcome to the Grocery Shop Chatbot!")
    while True:
        user_input = input("You: ").lower()
        if user_input == 'exit':
            print("Chatbot: Goodbye!")
            break
        else:
            response = get_response(user_input)
            print("Chatbot:", response)


main()
