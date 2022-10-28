import sys
sys.path.append(r"C:\ARCHLOG\Labo2\Lab2\x64\Release")
import Laboratoire2

from tkinter import *
import tkinter as tk
from tkinter import filedialog as fd

root = Tk()

def essais1():
   print("import")
   myfile = fd.askopenfilename(title="Choisir un fichier", filetypes = [( "tout les fichiers","*.*")])
   Laboratoire2.lecteur(myfile)

def retour():
    print("Retour au debut")
    Laboratoire2.RetourDebut()

def play_pause():
    print("play/pause")
    Laboratoire2.PlayVideo()
def speed():
    print("avance rapide")
    Laboratoire2.AvanceRapide()
def fermeture():
    Laboratoire2.Quit();
    root.destroy


importateur = Button(root,text="Importateur", command=essais1)
importateur.pack()

play_time = Button(root,text="Play/Pause",command=play_pause)
play_time.pack()

retourAuDebut = Button(root, text="Retour au debut", command=retour)
retourAuDebut.pack()

avanceRapide = Button(root, text="Avance Rapide", command=speed)
avanceRapide.pack()

quit = Button(root, text="QUIT", fg="red",command=fermeture)
quit.pack()
 
#Laboratoire2.lecteur(myfile)


root.mainloop()
Laboratoire2.lecteur(myfile)