# def printThem(s,i,n,temp):
#     if i==n : print(temp)
#     else :
#         printThem(s,i+1,n,temp)
#         printThem(s,i+1,n,temp+s[i])


# def printAllSubSequences(string):
#     l = len(string)
#     printThem(string,0,l,'')
    
# printAllSubSequences('Balu')

def printAllFun(lis):
    l = len(lis)
    printAllSubSeqs(lis,list(),l,0)

def printAllSubSeqs(lis,tempLis,l,ind):
    print(tempLis)
    if ind == l:
        print(tempLis)
    else:
        printAllSubSeqs(lis,tempLis.append(lis[ind]),l,ind+1)
        printAllSubSeqs(lis,tempLis,l,ind+1)

s = list(map(int,input("Enter the items in the list: ")))
printAllFun(s)