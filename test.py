class evaluation:
    def __init__(self):
        self.name = input("enter name of employee : ")
        self.compantancies = {
            "communication":[0,0,0],
            "productivity":[0,0,0],
            "Integrity":[0,0,0],
            "Punctuality":[0,0,0],
            "Creativity":[0,0,0],
        }

        self.performance = {
            "Goal1":[0,0,0],
            "Goal2":[0,0,0],
            "Goal3":[0,0,0],
            "Goal4":[0,0,0],
            "Goal5":[0,0,0],
        }

    def takeInput(self):
        print("enter rating 1-3")
        totalweightage = 0 
        for key in self.compantancies.keys():
            self.compantancies[key][0] = int(input(f"enter ratting for {key}:"))
            self.compantancies[key][1] = int(input(f"enter weightage {100-totalweightage} remaining:"))
            totalweightage+= self.compantancies[key][1]
            self.compantancies[key][2] = self.compantancies[key][1]*self.compantancies[key][0]/100   

        for key in self.performance.keys():
            self.performance[key][0] = int(input(f"enter ratting for {key}:"))
            self.performance[key][1] = int(input(f"enter weightage for {key} {100-totalweightage} remaining :"))
            self.performance[key][2] = self.performance[key][0]*self.performance[key][1]/100



    def calculate(self):
        total = 0 ;
        self.takeInput() 
        print("compantancies\t\tratting\tweightage\tscore")

        for key in self.compantancies.keys():
            print(f"{key}\t\t{self.compantancies[key][1]}\t\t{self.compantancies[key][2]}")
            total +=self.compantancies[key][2]
        print("\n")

        print("Goals\t\tratting\tweightage\tscore")
        for key in self.performance.keys():
            print(f"{key}\t\t{self.performance[key][0]}\t\t{self.performance[key][1]}\t\t{self.performance[key][2]}")
            total +=self.performance[key][2] 

        print("total ratting = ",total)
        if total>2.7 :
            print("employee pass the requirements")
        elif total>1.7 and total<=2.7 :
            print("employee meet requirements")
        else:
            print("employee does not meet requirements")


obj = evaluation();
obj.calculate() ;