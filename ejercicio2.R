carpeta<-"/home/jhoan/Escritorio" # primero guardamos la direccion del archivo
setwd(carpeta) #almacena la direccion del archivo
getwd() #obtiene la direccion del archivo
liga <- read.csv('SP1.csv') #al ya tener la di

levels(liga$FTR)
install.packages("dplyr")

library("dplyr")
tabla_simple <- select(liga, HomeTeam, FTHG, AwayTeam, FTAG, FTR)#sirve quitar columnas "select"
head(tabla_simple)

locales <- filter(tabla_simple, tabla_simple$FTR == "H")
head (locales)
write.csv(locales, "locales_17_18.csv")
dim(locales)
dim(visitantes)
dim(empates)