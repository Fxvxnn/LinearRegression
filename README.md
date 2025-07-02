# LinearRegression

The linearRegression.cpp File contains the model and a Function to read in csv Data. I have trained the model on the Student_Performance Dataset (https://www.kaggle.com/datasets/nikhil7280/student-performance-multiple-linear-regression) with a MSE of 4.55.

## Generalized Linear Models

Since the Gaussian distrubution is in the exponantial Family, we can apply a Generalized Linear Model. We try to adjust the parameters $\theta$ such that $h_\theta(x)= E[y|x;\theta]$ is satisfied. Additional we assume that $y|x;\theta \sim ExponantialFamily(\eta)$ where the Distrubution from the ExponantialFamily can be written as $p(y; \eta)=b(y)exp(\eta^TT(y)-a(\eta))$ and that $\eta$ and $x$ are related linearly ($\eta=\theta^Tx$).

Since the Vareince has no effect on $h_\theta(x)$ we can set it to 1 and are left with 

$p(y;\mu)=\fraq{1}{\sqrt{2\pi}}exp(-1/2(y-\mu)^2)$

$p(y;\mu)=\fraq{1}{sqrt(2\pi)}exp(-1/2y^2)*exp(\mu y-1/2\mu^2)$

