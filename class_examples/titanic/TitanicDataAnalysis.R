
#Load raw data
train <- read.csv("titanic/train.csv", header = TRUE)
test <- read.csv("titanic/test.csv", header = TRUE)

#Add a "S" var
test.survived <- data.frame(survived = rep("None", nrow(test)), test[,])

#Combine
data.combined <- rbind(train, test.survived)

str(data.combined)

data.combined$survived <- as.factor(data.combined$survived)
data.combined$pclass <- as.factor(data.combined$pclass)

