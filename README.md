# LinearRegression

The linearRegression.cpp File contains the model and a Function to read in csv Data. I have trained the model on the Student_Performance Dataset (https://www.kaggle.com/datasets/nikhil7280/student-performance-multiple-linear-regression) with a MSE of 4.55.

## Generalized Linear Models

Since the Gaussian distrubution is in the exponantial Family, we can apply a Generalized Linear Model. We try to adjust the parameters $\theta$ such that $h_\theta(x)= E[y|x;\theta]$ is satisfied. Additional we assume that $y|x;\theta \sim ExponantialFamily(\eta)$ where the Distrubution from the ExponantialFamily can be written as $p(y; \eta)=b(y)exp(\eta^TT(y)-a(\eta))$ and that $\eta$ and $x$ are related linearly ($\eta=\theta^T*x$).

