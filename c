#1 Import Libraries 
import pandas as pd
import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from textblob import TextBlob
import matplotlib.pyplot as plt
import seaborn as sns
from wordcloud import WordCloud

nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('stopwords')
sns.set_style('whitegrid')

#2 Dataset
data = {
    'reviews': [
        'Product is very good',
        'Excellent quality and fast delivery',
        'Amazing experience',
        'Very nice product',
        'Good service',
        'Bad quality',
        'Very poor service',
        'Product is average',
        'It is normal',
        'No comments'
    ]
}

df = pd.DataFrame(data)
df

#3 Preprocessing
stop_words = set(stopwords.words('english'))

def preprocess(text):
    tokens = word_tokenize(text.lower())
    tokens = [w for w in tokens if w.isalpha()]
    tokens = [w for w in tokens if w not in stop_words]
    return ' '.join(tokens)

df['clean_reviews'] = df['reviews'].apply(preprocess)
df

#4 Sentiment Analysis
def get_sentiment(text):
    polarity = TextBlob(text).sentiment.polarity
    if polarity > 0.3:
        return 'Positive'
    elif polarity < -0.3:
        return 'Negative'
    return 'Neutral'

df['sentiment'] = df['clean_reviews'].apply(get_sentiment)
df

#5 Visualization 
plt.figure()
df['sentiment'].value_counts().reindex(['Positive','Negative','Neutral']).plot(kind='bar')
plt.title('Customer Sentiment Distribution')
plt.show()

#6 WordCloud Visualization
text = ' '.join(df['clean_reviews'])
wc = WordCloud(background_color='white').generate(text)

plt.imshow(wc)
plt.axis('off')
plt.show()
