data albumDetails = albumDetails {
	version :: String,
	songs :: Integer,	-- defining number of songs on each album. average number of songs provided
	runTime :: Float	-- number of minutes the album is approximately
}

Mini :: albumDetails
Mini = 	albumDetails {
	version = "Mini",
	songs = 6,
	runTime = 30.0
}

Single :: albumDetails
Single = 	albumDetails {
	version = "Single",
	songs = 3,
	runTime = 10.0
}

Full :: albumDetails
Full = 	albumDetails {
	version = "Full",
	songs = 12,
	runTime = 60.0
}

printAlbumDetails :: albumDetails -> IO ()
printAlbumDetails music = do
    putStrLn ("The " ++ show (version music) ++ " album has " ++ show (songs music) ++ " songs.")

-- Usage:
main = do
    printAlbumDetails Mini
    printAlbumDetails Full