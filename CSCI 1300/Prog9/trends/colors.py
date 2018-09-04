def get_sentiment_color(sentiment):
    """Returns a color corresponding to the sentiment value.

    sentiment -- a number between 1 (blue) and 9 (red)
    """
    if sentiment is None:
        return (0,0,0)    # BLACK

    # Convert the 1 to 9 scale to a -1 to +1 scale
    if sentiment > 1:
        spread = 1.5
        sentiment = 5 + spread*(sentiment-5)
        sentiment = -1 + 2.0*(sentiment-1)/8

    red = max(0, min(255, 255*(sentiment+0.5)))
    green = max(0, min(255, 255 - 255*abs(sentiment)))
    blue = max(0, min(255, 255*(0.5-sentiment)))

    return (red,green,blue)
