class transceiver:
    def __init__(self,colors):
        self.red=colors[0]
        self.green=colors[1]
        self.bleu=colors[2]
        self.colors=[self.red,self.green,self.bleu]
    def sort_colors(self):
        tbs=["red","green","bleu"]
        for i in range(0,3):
            for j in range(0,i):
                if(self.colors[j]<self.colors[i]):
                    temp=self.colors[i]
                    self.colors[i]=self.colors[j]
                    self.colors[j]=temp
                    new_temp=tbs[i]
                    tbs[i]=tbs[j]
                    tbs[j]=new_temp
        return tbs