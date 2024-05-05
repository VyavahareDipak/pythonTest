import random

response={
    "greeting":["hi, welcome to our shop","hello","hello ,how can I help you"],
    "farewell":["bye ,have a good day!","Thanks for visiting. see you soon!"],
    "thank":["You're welcome!","My plesure","No Problem!"],
    "product":["we have all grocery products","Dairy products are also available"],
    "time":["shop open at 9:00 AM and close at 9:00 PM every day except sunday","We are open from 9:00 AM to 9:00 PM,monday to saturday "],
    "location":["Our location is 123 street"],
    "default":["Could you rephrase that ?","Sorry I didn't understand that"] 
}

def chatout(user_input):
    if "hey" in user_input or "hello" in user_input or "hi" in user_input:
        return random.choice(response["greeting"])
    elif "Bye" in user_input:
        return random.choice(response["farewell"])
    elif "product" in user_input:
        return random.choice(response["product"])
    elif "hour" in user_input or "time" in user_input or "close" in user_input or "open" in user_input:
        return random.choice(response["time"])
    else:
        return random.choice(response["default"])

def main():
    print("wellcome to our general store")
    
    while True:
        user_input = input() ;
        if user_input=="exit":
            print("chatbot:Goodbye")
            break 
        else:
            print("chatbot:",chatout(user_input))

main()