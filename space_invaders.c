void logic()
{
    if (bulletActive)
    {
        bulletY--;
        if (bulletY < 0)
        {
            bulletActive = false;
        }
    }
    bool edgeReached = false;
    int activeAliensCount = 0;

    for ( int i = 0; i < NUM_ALIENS; i++)
    {
        if (aliens[i].active)
        {
            activeAliensCount++;
            if (bulletActive && bulletX == aliens[i].x && bulletY == aliens[i].y)
        {
            aliens[i].active = false;
            bulletActive = false;
            score += 10;
        }
        if (aliens[i].y >= HEIGHT - 1)
        {
            lives--;

            if(lives > 0)
            {
                for (int j = 0; j < NUM_ALIENS; j++)
                {
                    aliens[j].x = (j % 5) * 6 + 5;
                    aliens[j].y = (j / 5) * 2 + 2;
                    aliens[j]. active = true;
                }
                alienDirection = 1;
                bulletActive = false;
                return;
            }
        }
        if (aliens[i].x + alienDirection >= WIDTH || aliens[i].x + alienDirection < 0)
        {
            edgeReached = true;
        }
        }
    }
}
