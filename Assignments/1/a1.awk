BEGIN { FS=":" }

function parse()
{
	for ( i=2; i<=NF; i++ ) {
		printf( "\t\t<file>" )
		printf( $i )
		printf( "</file>\n" ) 
	}
}

$1=="index" {
	parse()
	printf( "\t</index>\n" )
}

$1=="required" {
	printf( "\t<required>\n" )
	parse()
}
