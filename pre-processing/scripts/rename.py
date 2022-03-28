import os
 
# Function to rename multiple files
def main():
    count1=86
    folder = "/home/harshvardhan/Documents/Major_Project/pre-processing/data/cpp/cpp2"
    for count, filename in enumerate(os.listdir(folder)):
        dst = f"{str(count1)}.cpp"
        count1+=1
        src =f"{folder}/{filename}"  # foldername/filename, if .py file is outside folder
        dst =f"{folder}/{dst}"
         
        # rename() function will
        # rename all the files
        os.rename(src, dst)
 
# Driver Code
if __name__ == '__main__':
     
    # Calling main() function
    main()