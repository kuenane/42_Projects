#!/bin/bash

# Réaliser un script qui permet de surveiller les modifications du fichier /etc/crontab et envoie un mail à root si celui-ci a été modifié

OUTPUT_INSTEAD_OF_SEND_MAIL=false

FILE_TO_CHECK="/etc/crontab"

while true
do
	touch LOGFILE TMPLOGFILE

	# if files don't exist, error
	if [ ! -f "LOGFILE" ] || [ ! -f "TMPLOGFILE" ]; then
		echo "error: problem with logfiles..."
		exit 1
	fi

	# cp cronfile to tmpfile (to be sure the file checked is the same copied to logfile after)
	cp "$FILE_TO_CHECK" TMPLOGFILE

	# diff piped wc to get number of chars (to check if != 0)
	if [ `diff LOGFILE TMPLOGFILE | wc -c | tr -d " "` -ne 0 ]; then
		# save the file
		cp TMPLOGFILE LOGFILE

		if [ OUTPUT_INSTEAD_OF_SEND_MAIL = false ]; then
			# send mail
			printf "[`date`] crontab edited" | mail -s "crontab edited" `cat /var/mail/root`
		else
			# debug enabled, print to stdout
			echo "[`date`] crontab edited"
		fi
	fi
done
