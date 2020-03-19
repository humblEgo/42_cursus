<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wpdb' );

/** MySQL database username */
define( 'DB_USER', 'wpuser' );

/** MySQL database password */
define( 'DB_PASSWORD', '1111' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define( 'SECURE_#f[JrGXBh5aAyl0$>0Y@Olc DF[M#JZ?rJy.#cWJO,3jNIm(O_m.d)N^VsL');
define('SECURE_AUTH_KEY',  'l3|:U)lQ1Pr3T<]+#YyUf&!m7&Y#WxE3 ^  <)^H*^tBSCMTd!Q|S.i9PA=0_]sw');
define('LOGGED_IN_KEY',    '<wKZ*x_zhOlrqc(pLTQmHG-wg[9K+34qW4|ZR05QC7+s%]|^YCSL%-N 3a.=J3)&');
define('NONCE_KEY',        '#L8k#fO2-A*zq@ezThrb#P-1_Rr5(pe<QqMOx?VRSOR(pnL|+dMp,@{M9uJD){1+');
define('AUTH_SALT',        'N^v;~e[h6hoMppjLWv>}QZ(:QBt<<forVY+fftf<lxwVY8WzKP VsZZ9-`TE]&KY');
define('SECURE_AUTH_SALT', '5]xrzCE;$y+7XfvxU,~UR:,%kdn?so:qW|]<c8~AaDX+6Bg,o2xI:^@7%>CZ-ymX');
define('LOGGED_IN_SALT',   'hm)+b+f(zV4>7Uk.*]YBQ+0KaM<EL>,,vU-/P!-zNZ6FZSa+]N{rNGbljVDe[PO=');
define('NONCE_SALT',       'EJQGBOMDNde>-tfZ,m]|ZZ*HCla^UQ|!ffS22Rv-zD-zWV(tTwk(U%sPM}}Z+K-t');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
