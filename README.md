# LinearRegression

The linearRegression.cpp File contains the model and a Function to read in csv Data. I have trained the model on the Student_Performance Dataset (https://www.kaggle.com/datasets/nikhil7280/student-performance-multiple-linear-regression) with a MSE of 4.55.

## Generalized Linear Models

We try to train our model to predict a target value $y$ given the input features $\vec{x}$. When we have multiple Sets of inputs and outputs I describe the features as $X$ and the targets as $\vec{y}$.  
Since our targets are real numbers and the Gaussian distrubution is in the exponantial Family, we can apply a Generalized Linear Model. We try to adjust the parameters $\theta$ such that $h_\theta(x)= E[y|x;\theta]$ is satisfied. Additional we assume that $y|x;\theta \sim ExponantialFamily(\eta)$ where the Distrubution from the ExponantialFamily can be written as $p(y; \eta)=b(y)exp(\eta^TT(y)-a(\eta))$ and that $\eta$ and $x$ are related linearly ($\eta=\theta^Tx$).

Since the Vareince has no effect on $h_\theta(x)$ we can set it to 1 and are left with  
$p(y;\mu)=\frac{1}{\sqrt{2\pi}}exp(-\frac{1}{2}(y-\mu)^2)$  
$p(y;\mu)=\frac{1}{\sqrt{2\pi}}exp(-\frac{1}{2}y^2)*exp(\mu y-\frac{1}{2}\mu^2)$

From this we can see  
$b(y)=\frac{1}{\sqrt{2\pi}}exp(-\frac{1}{2}y^2)$  
$\eta=\mu$  
$T(y)=y$  
$a(\eta)=\frac{\mu^2}{2}=\frac{\eta^2}{2}$

Now $h_\theta(x)$ follows from $h_\theta(x)= E[y|x;\theta]$.  
$h_\theta(x)= E[y|x;\theta]=\mu=\eta$  
$h_\theta(x)=\theta^Tx$

To adjust the parameters $\theta$ we can maximize the Likelihood $L(\theta)=p(\vec{y}|X;\theta)=\prod_{i=1}^{m} p(y^{(i)}|x^{(i)};\theta)$ with gradient descent.  
Since the $log$-function is strictly increasing we can also maximize this, to make the algebra a bit easier.  
$l(\theta)=\log(L(\theta))=\sum_{i=1}^{m} \log(p(y^{(i)}|x^{(i)};\theta))$  
$l(\theta)=\sum_{i=1}^{m} \log(\frac{1}{\sqrt{2\pi}\sigma}exp(-\frac{1}{2\sigma^2}(y^{(i)}-\theta^Tx^{(i)})^2))=m\log(\frac{1}{\sqrt{2\pi}\sigma})-\frac{1}{\sigma^2}*\frac{1}{2}\sum_{i=1}^{m}(y^{(i)}-\theta^Tx^{(i)})^2$  
From there we see, that the choice of $\theta$ doesn't depend on $\sigma$. Additional we see, maximizing $l(\theta)$ gives the same results as minimizing $\frac{1}{2}\sum_{i=1}^{m}(y^{(i)}-\theta^Tx^{(i)})^2$ which I define as my Cost-function $J(\theta)$.  

