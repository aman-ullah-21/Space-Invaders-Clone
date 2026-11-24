// Updates game rules, bullet flight, alien movement, wave respawning, and collisions
void logic()
{
    // Move active bullet upward and deactivate if it leaves the top boundary
    if (bulletActive)
    {
        bulletY--;
        if (bulletY < 0)
        {
            bulletActive = false;
        }
    }

    bool edgeReached = false;      // Tracks whether any active alien hits the left or right wall
    int activeAliensCount = 0;   // Counts how many aliens are currently alive

    for (int i = 0; i < NUM_ALIENS; i++)
    {
        if (aliens[i].active)
        {
            activeAliensCount++;

            // Check collision between bullet and active alien
            if (bulletActive && bulletX == aliens[i].x && bulletY == aliens[i].y)
            {
                aliens[i].active = false;  // Destroy hit alien
                bulletActive = false;      // Remove bullet after impact
                score += 10;               // Increase player score
            }

            // Deduct a life if an alien reaches the bottom row
            if (aliens[i].y >= HEIGHT - 1)
            {
                lives--;

                // Reset alien formation and direction if lives remain
                if (lives > 0)
                {
                    for (int j = 0; j < NUM_ALIENS; j++)
                    {
                        aliens[j].x = (j % 5) * 6 + 5;
                        aliens[j].y = (j / 5) * 2 + 2;
                        aliens[j].active = true;
                    }
                    alienDirection = 1;
                    bulletActive = false;
                    return; // Skip further movement this frame after reset
                }
            }

            // Detect if moving horizontally would push the alien past the side borders
            if (aliens[i].x + alienDirection >= WIDTH || aliens[i].x + alienDirection < 0)
            {
                edgeReached = true;
            }
        }
    }

    // Spawn a fresh wave of aliens once all active aliens are defeated
    if (activeAliensCount == 0)
    {
        for (int i = 0; i < NUM_ALIENS; i++)
        {
            aliens[i].x = (i % 5) * 6 + 5;
            aliens[i].y = (i / 5) * 2 + 2;
            aliens[i].active = true;
        }
        alienDirection = 1;
    }

    // Reverse horizontal direction and step down on wall hit; otherwise move sideways
    if (edgeReached)
    {
        alienDirection *= -1;
        for (int i = 0; i < NUM_ALIENS; i++)
        {
            if (aliens[i].active)
            {
                aliens[i].y++;
            }
        }
    }
    else
    {
        for (int i = 0; i < NUM_ALIENS; i++)
        {
            if (aliens[i].active)
            {
                aliens[i].x += alienDirection;
            }
        }
    }
}
