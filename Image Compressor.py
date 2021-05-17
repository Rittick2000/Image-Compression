import PIL
import PIL.Image
from tkinter.filedialog import *
from tkinter import *

root=Tk()
root.geometry('200x200')
root.title("Image Compressor")
root.resizable(0,0)
frame=Frame(root)
frame.pack(side=BOTTOM,padx=15,pady=15)

def open_file():
    file_path = askopenfilename()
    img = PIL.Image.open(file_path)
    mheight,mwidth =map(int,img.size)
    img = img.resize((mheight,mwidth),PIL.Image.ANTIALIAS)
    save_path = asksaveasfilename()
    img.save(save_path + ".jpg")
    ss=save_path+".jpg"
    immg=PIL.Image.open(ss)
    immg.show()


button1=Button(root,text="select file",font=('arial',10,'bold'),fg='blue',activebackground='green',relief=GROOVE,command=open_file)
button1.pack(pady=10)

button2=Button(frame,text="Exit",font=('arial',10,'bold'),fg='black',relief=SUNKEN,command=lambda:exit())
button2.pack(padx=12,pady=12)

root.mainloop()



