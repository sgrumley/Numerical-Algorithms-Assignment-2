#include <bits/stdc++.h>
#define PI 3.14159265

using namespace std;

double errorFunction(double total, double current) {
    return (total * current / total) * 100;
}

double f(double x) {
    double part = x - (x * x) / 10;

    // * PI / 180.0
    return 2 * sin(part);
}

void brentsMethod(double lower_bound, double upper_bound, double TOL, double MAX_ITER) {
    double a  = lower_bound;
    double b  = upper_bound;
    double fa = f(a); // calculated now to save function calls
    double fb = f(b); // calculated now to save function calls
    double fs = 0;    // initialize


    // d is the current estimate for the optimum point
    double xTop =  pow((b - a), 2) * (f(b) - f(c)) - pow((b - c), 2) * (f(b) - f(a));
    double xBot = (b - a) * (f(b) - f(c)) - (b - c) * (f(b) - f(a));
    double d    = b - 0.5 * (xTop / xBot);

    // use d and f(d) to reduce bracating interval


    if (d > b) {
        if (f(d) > f(b)) {
            // d is in the higher sub interval, discard lower interval
            a = a;
            b = d;
            c = b;
        }

        if (f(d) < f(b)) {
            // d is in the lower sub interval, discard higher interval
            a = d;
            b = b;
            c = c;
        }
    }

    if (d < b) {
        if (f(d) > f(b)) {
            // d is in the upper sub interval, discard lower interval
            a = b;
            b = d;
            c = c;
        }

        if (f(d) < f(b)) {
            // d is in the lower sub interval, discard higher interval
            a = a;
            b = b;
            c = d;
        }
    }
}

int main() {
    // Brents's method for finding max of function
    double TOL = 0.0001;
    double a   = -2;
    double b   = 2;

    brentsMethod(-2, 2, TOL, 9999);
}

void brents_fun(std::function<double(double)>f, double lower_bound, double upper_bound, double TOL, double MAX_ITER)
{
    double a  = lower_bound;
    double b  = upper_bound;
    double fa = f(a); // calculated now to save function calls
    double fb = f(b); // calculated now to save function calls
    double fs = 0;    // initialize

    if (!(fa * fb < 0))
    {
        std::cout << "Signs of f(lower_bound) and f(upper_bound) must be opposites" << std::endl; // throws exception if root isn't bracketed
        return;
    }

    if (std::abs(fa) < std::abs(b)) // if magnitude of f(lower_bound) is less than magnitude of f(upper_bound)
    {
        std::swap( a,  b);
        std::swap(fa, fb);
    }

    double c     = a;    // c now equals the largest magnitude of the lower and upper bounds
    double fc    = fa;   // precompute function evalutation for point c by assigning it the same value as fa
    bool   mflag = true; // boolean flag used to evaluate if statement later on
    double s     = 0;    // Our Root that will be returned
    double d     = 0;    // Only used if mflag is unset (mflag == false)

    for (unsigned int iter = 1; iter < MAX_ITER; ++iter)
    {
        // stop if converged on root or error is less than tolerance
        if (std::abs(b - a) < TOL)
        {
            std::cout << "After " << iter << " iterations the root is: " << s << std::endl;
            return;
        } // end if

        if ((fa != fc) && (fb != fc))
        {
            // use inverse quadratic interopolation
            s =   (a * fb * fc / ((fa - fb) * (fa - fc)))
                + (b * fa * fc / ((fb - fa) * (fb - fc)))
                + (c * fa * fb / ((fc - fa) * (fc - fb)));
        }
        else
        {
            // secant method
            s = b - fb * (b - a) / (fb - fa);
        }

        /*
            Crazy condition statement!:
            -------------------------------------------------------
            (condition 1) s is not between  (3a+b)/4  and b or
            (condition 2) (mflag is true and |s−b| ≥ |b−c|/2) or
            (condition 3) (mflag is false and |s−b| ≥ |c−d|/2) or
            (condition 4) (mflag is set and |b−c| < |TOL|) or
            (condition 5) (mflag is false and |c−d| < |TOL|)
         */
        if (((s < (3 * a + b) * 0.25) || (s > b)) ||
            (mflag && (std::abs(s - b) >= (std::abs(b - c) * 0.5))) ||
            (!mflag && (std::abs(s - b) >= (std::abs(c - d) * 0.5))) ||
            (mflag && (std::abs(b - c) < TOL)) ||
            (!mflag && (std::abs(c - d) < TOL)))
        {
            // bisection method
            s = (a + b) * 0.5;

            mflag = true;
        }
        else
        {
            mflag = false;
        }

        fs = f(s);       // calculate fs
        d  = c;          // first time d is being used (wasnt used on first iteration because mflag was set)
        c  = b;          // set c equal to upper bound
        fc = fb;         // set f(c) = f(b)

        if (fa * fs < 0) // fa and fs have opposite signs
        {
            b  = s;
            fb = fs;     // set f(b) = f(s)
        }
        else
        {
            a  = s;
            fa = fs;                     // set f(a) = f(s)
        }

        if (std::abs(fa) < std::abs(fb)) // if magnitude of fa is less than magnitude of fb
        {
            std::swap( a,  b);           // swap a and b
            std::swap(fa, fb);           // make sure f(a) and f(b) are correct after swap
        }
    } // end for

    std::cout << "The solution does not converge or iterations are not sufficient" << std::endl;
}
