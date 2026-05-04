Aim
To perform sentiment analysis on customer reviews using text analytics techniques
and classify them into positive, negative, and neutral categories, and visualize the results.

Theory
Social media platforms generate a large amount of unstructured data such as customer reviews and comments.
This data can be analyzed using text analytics techniques to extract useful insights.

Text Analytics:
It is the process of converting unstructured text data into meaningful information using Natural Language Processing (NLP).

Sentiment Analysis:
It classifies text into:
Positive
Negative
Neutral

Text Preprocessing:
Before analysis, text data is cleaned using:
Tokenization (splitting text into words)
Stop-word removal (removing common words like “is”, “the”)
Lowercasing

Sentiment Classification:
In this experiment, sentiment is determined using the polarity score from TextBlob:
Polarity > 0 → Positive
Polarity < 0 → Negative
Polarity ≈ 0 → Neutral

Visualization:
Bar chart is used to show sentiment distribution
WordCloud is used to display frequently occurring words

Procedure
Collect customer review data
Create dataset using Python
Perform text preprocessing (tokenization, stop-word removal)
Apply sentiment analysis using TextBlob
Classify reviews into positive, negative, and neutral
Visualize sentiment distribution using a bar chart
Generate WordCloud for important words
