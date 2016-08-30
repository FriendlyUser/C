using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MathQuiz
{
    public partial class Form1 : Form
    {
        // Create a Random object called randomizer
        // to generate random numbers.
        Random randomizer = new Random();
        // integer variables store numbers for the addition problem
        int addend1;
        int addend2;

        // These integers store numbers for the subtraction problem
        int minuend;
        int subtrahend;
        // This integer keeps track of the
        // remaining time.

        // These integer variables store the numbers
        // for the multiplication problem.
        int multiplicand;
        int multiplier;

        // These integer variables store the numbers
        // for the division problem.

        int dividend;
        int divisor;

        int timeLeft;   // Keep track of the remaining time
        /// <summary>
        /// Start the quiz by filling in all of the problems
        /// and starting the timer.
        /// </summary>
        public void StartTheQuiz()
        {
            //Fill in the addition problem.
            //Generate two random numbers to add
            //Store the values in the variables 'addend1' and 'addend2'.
            addend1 = randomizer.Next(51);
            addend2 = randomizer.Next(51);
            //Convert the two randomly generated numbers
            // into strings so that they can be displayed
            // in the label controls
            plusLeftLabel.Text = addend1.ToString();
            plusRightLabel.Text = addend2.ToString();

            // Set  NumericUpDown control named sum as zero.
            sum.Value = 0;

            // Fill in the subtraction problem
            minuend = randomizer.Next(1, 101);
            subtrahend = randomizer.Next(1, minuend);
            minusLeftLabel.Text = minuend.ToString();
            minusRightLabel.Text = subtrahend.ToString();
            difference.Value = 0;

            //Fill in the multiplication problem.
            multiplicand = randomizer.Next(2, 11);
            multiplier = randomizer.Next(2, 11);
            timesLeftLabel.Text = multiplicand.ToString();
            timesRightLabel.Text = multiplier.ToString();
            product.Value = 0;

            // Fill in the division problem
            divisor = randomizer.Next(2, 11);
            int temporaryQuotient = randomizer.Next(2, 11);
            dividend = divisor * temporaryQuotient;
            dividedLeftLabel.Text = dividend.ToString();
            dividedRightLabel.Text = divisor.ToString();
            quotient.Value = 0;
            // Start the timer
            timeLeft = 30;
            timeLabel.Text = "30 seconds";
            timer1.Start();
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void plusRightLabel_Click(object sender, EventArgs e)
        {

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            // if number is correct play correct.wave
            if (addend1 + addend2 == sum.Value
                || (minuend - subtrahend == difference.Value)
                || (multiplicand * multiplier == product.Value)
                || (dividend / divisor == quotient.Value))
            {
                System.Media.SoundPlayer player =
                new System.Media.SoundPlayer();
                player.SoundLocation = @"C:\Users\wu\Documents\Visual Studio 2015\Projects\MathQuiz\MathQuiz\correct.wav";
                player.Load();
                player.Play();
            }
            // play button.wav
            else
            {
                System.Media.SoundPlayer player =
                new System.Media.SoundPlayer();
                player.SoundLocation = @"C:\Users\wu\Documents\Visual Studio 2015\Projects\MathQuiz\MathQuiz\button.wav";
                player.Load();
                player.Play();
            }

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void startButton_Click(object sender, EventArgs e)
        {
            StartTheQuiz();
            timeLabel.BackColor = Color.Transparent;
            startButton.Enabled = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // Check to see if the user has got the right answer
            // Congratulate the user and allow 
            // the user to start another quiz 
            if (CheckTheAnswer())
            {
                timer1.Stop();
                MessageBox.Show("You got all the answers right!",
                        "Congratulations!");
                startButton.Enabled = true;
            }
            else if (timeLeft > 0)
            {
                //Display the new time left
                // by updating the Time Left Label
                timeLeft = timeLeft - 1;
                timeLabel.Text = timeLeft + " seconds";

                // Check the colour of the timeLabel 
                // depending on the remaining amount of time
                if (timeLeft < 25 && timeLeft > 15)
                {
                    timeLabel.BackColor = Color.Green;
                }
                else if (timeLeft < 15 && timeLeft > 5)
                {
                    timeLabel.BackColor = Color.Orange;
                }
                else if(timeLeft < 5)
                {
                    timeLabel.BackColor = Color.Red;
                }
            }
            else
            {
                //play game over sound
                System.Media.SoundPlayer player =
                new System.Media.SoundPlayer();
                player.SoundLocation = @"C:\Users\wu\Documents\Visual Studio 2015\Projects\MathQuiz\MathQuiz\gameover.wav";
                player.Load();
                player.Play();

                //If a user ran out of time, stop the timer, show
                // a MessageBox, and reveal the answers
                timer1.Stop();
                timeLabel.Text = "Time's up!";
                MessageBox.Show("You did not finish in time.", "Sorry!");
                sum.Value = addend1 + addend2;
                difference.Value = minuend - subtrahend;
                product.Value = multiplicand * multiplier;
                quotient.Value = dividend / divisor;
                startButton.Enabled = true;
            }
        }
        private bool CheckTheAnswer()
        {
            if (addend1 + addend2 == sum.Value 
                && (minuend - subtrahend == difference.Value)
                && (multiplicand * multiplier == product.Value)
                && (dividend / divisor == quotient.Value))
                return true;
            else
                return false;
        }
        private void answer_Enter(object sender, EventArgs e)
        {
            // Select the whole answer in the NumericUpDown control.
            NumericUpDown answerBox = sender as NumericUpDown;

            if (answerBox != null)
            {
                int lengthOfAnswer = answerBox.Value.ToString().Length;
                answerBox.Select(0, lengthOfAnswer);
            }
        }
    }
}
